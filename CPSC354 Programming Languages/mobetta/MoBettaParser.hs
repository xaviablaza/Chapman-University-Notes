module MoBettaParser where

-- Parser for MoBetta.

import Control.Applicative
import Text.Megaparsec
import Text.Megaparsec.Char -- various basic parsers
import qualified Text.Megaparsec.Char.Lexer as L
import Text.Megaparsec.Expr
import Data.Void

import MoBettaAST

-- Simplest use of Parsec is all we need.

type Parser = Parsec Void String


programParser = sepEndBy1 statementParser semicolon <?>  "program"


statementParser = choice
  [   skipStmt
    , printStmt
    , messageStmt
    , readStmt
    , ifStmt
    , whileStmt
    , assignmentStmt
    , blockStmt
  ] where
    skipStmt = lexeme (string "skip") >> return Skip
    printStmt = do
      lexeme (string "print")
      e <- aExpr
      return (Print e)
    readStmt = do
      lexeme (string "read")
      i <- identifier
      return (Read i)
    messageStmt = do
      lexeme (string "message")
      s <- stringLiteral
      return (Msg s)
    ifStmt = do
      lexeme (string "if")
      b <- bExpr
      lexeme (string "then")
      t <- statementParser
      lexeme (string "else")
      e <- statementParser
      return (If b t e)
    whileStmt = do
      lexeme (string "while")
      b <- bExpr
      lexeme (string "do")
      e <- statementParser
      return (While b e)
    assignmentStmt = do
      v <- identifier
      lexeme (string "=")
      e <- aExpr
      return (Assign v e)
    blockStmt = do
      lbrace
      p <- programParser
      rbrace
      return (Block p)

aExpr = makeExprParser aFactor aOpTable <?> "arithmetic expression"

-- parenthesized expressions are missing
aFactor = choice [ intConst
                , identifierExpr
                , between lparen rparen aExpr
                ] <?> "arithmetic factor"

aOpTable = [ [ prefix  "-"  (AUn Neg)
            , prefix  "+" id ] -- including a prefix + sign
          , [ binary  "*"  (ABin Mul)
            , binary  "/"  (ABin Div)
            , binary  "%"  (ABin Mod)]
          , [ binary  "+"  (ABin Add)
            , binary  "-"  (ABin Sub)  ] ]

bExpr = makeExprParser bFactor bOpTable <?> "booelan expression"
bFactor = choice [bConst,try comparison,between lparen rparen bExpr] <?> "boolean factor"
bOpTable = [[prefix "!" (BUn Not)]
            ,[binary "&&" (BBin And),binary "||" (BBin Or)]
           ]

-- bExpr :: Parser BExpr
-- bExpr = choice
--   [ unBExpr
--   , parenBExpr
--   , constBExpr
--   , compBExpr
--   , binBExpr
--   ] where
--     compBExpr  = do
--       x <- aExpr
--       b <- comparator
--       y <- aExpr
--       return (Reln b x y)
--     constBExpr = do
--       b <- boolConst
--       return (BoolConst b)
--     binBExpr = do
--       x <-bExpr
--       b <-binBOp
--       y <-bExpr
--       return (BBin b x y)
--     unBExpr = do
--       b <-unBOP
--       x <-bExpr
--       return (BUn b x)
--     parenBExpr = do
--       lparen
--       b <-bExpr
--       rparen
--       return (ParenBExpr b)

comparison = do
  a <-aExpr
  c <-comparator
  b <-aExpr
  return (Reln c a b)

comparator = choice compTable <?> "comparator"

compTable = [
    atomic "<="  LessEqual
  , atomic "<" Less
  , atomic ">="  GreaterEqual
  , atomic ">" Greater
  , atomic "==" Equal
  , atomic "!=" NEqual
  ]

-- These help declare parsers for operators such as "+", "and", "<=", "not" etc.
binary  opName f = InfixL (atomic opName f) -- make a left associative binary
prefix  opName f = Prefix (atomic opName f) -- make a prefix operator
atomic  opName f = f <$ lexeme (string opName) -- just parse the operator by itself and return a specified result (f).


spaceConsumer :: Parser ()
spaceConsumer = L.space space1 lineCmnt blockCmnt
  where
    lineCmnt  = L.skipLineComment "//"
    blockCmnt = L.skipBlockComment "/*" "*/"

-- Define a wrapper that consumes space after a parser
lexeme :: Parser a -> Parser a
lexeme = L.lexeme spaceConsumer

lparen = lexeme (char '(')
rparen = lexeme (char ')')
semicolon = lexeme (char ';')
lbrace = lexeme (char '{')
rbrace = lexeme (char '}')


identifier :: Parser String
identifier = (lexeme . try) p
  where
    p = (:) <$> letterChar <*> many alphaNumChar

identifierExpr = Var <$> identifier

stringLiteral :: Parser String
stringLiteral = char '"' *> manyTill L.charLiteral (char '"')

intConst :: Parser AExpr
intConst = fmap IntConst intConst'
  where
    intConst' = (lexeme . try) ic
    ic = do
          x <- L.decimal -- parse a literal
          notFollowedBy letterChar -- fail if followed by a letter
          return x -- return the  result if we haven't failed

bConst = do
  b <- boolConst
  return (BoolConst b)

boolConst = choice [atomic "True" True, atomic "False" False]

-- binBOp = choice [atomic "&&" And, atomic "||" Or]
--
-- unBOP = (atomic "!" Not)

tryit p = parse p "(--)"

mbparse = parse programParser
