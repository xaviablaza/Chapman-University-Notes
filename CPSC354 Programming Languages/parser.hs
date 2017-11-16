module AExprParser where

import Control.Applicative
import Text.Megaparsec
import Text.Megaparsec.Char -- various basic parsers
import qualified Text.Megaparsec.Char.Lexer as L
import Text.Megaparsec.Expr

data BExpr
  = Reln Comp AExpr AExpr
  | BoolConst Bool
  | And BExpr BExpr
  | Or BExpr BExpr
  | Not BExpr
  deriving (Show)

data Comp
  = Less
  | LessEqual
  | Greater
  | GreaterEqual

-- The abstract syntax of expressions
-- What the expression is
data AExpr
  = Var String
  | IntConst Integer -- an integer is an expression
  | Add AExpr AExpr -- add an expression to another expression
  | Sub AExpr AExpr -- subtract
  | Mul AExpr AExpr -- multiply
  | Div AExpr AExpr -- divide
  | Mod AExpr AExpr -- mod
  | Neg AExpr -- negate
  deriving (Show)

-- takes a string and would produce this output
examplesAExpr :: [(String, AExpr)]
examplesAExpr = [
    ("x", Var "x"),
    ("x + 5", Add (Var "x") (IntConst 5)),
    ("(x - 4)*(x + 4)", Mul (Sub (Var "x") (IntConst 4)) (Add (Var "x") (IntConst 4))),
    ("x + 6*z", Add (Var "x") (Mul (IntConst 6) (Var "z")))
  ]


type Parser = Parsec () String

-- The <?> Combinator informs a parser how to label a failed parser

expr = makeExprParser factor opTable <?> "expression"

-- parenthesized expressions are missing
factor = choice [ intConst
                , identifier
                , between lparen rparen expr
                ] <?> "factor"

opTable = [ prefix  '-'  Neg
            , prefix  '+'  id ] -- including a prefix + sign
          , [ binary  '*'  Mul
            , binary  '/'  Div
            , binary  '%'  Mod]
          , [ binary  '+'  Add
            , binary  '-'  Sub  ] ]

-- These help declare operators
-- They don't handle white space.
binary  opName f = InfixL $ (lexeme . try) (f <$ char opName)
prefix  opName f = Prefix $ (lexeme . try) (f <$ char opName)

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

identifier :: Parser AExpr
identifier = Var <$> (lexeme . try) p
  where
    p = (:) <$> letterChar <*> many alphaNumChar


intConst :: Parser AExpr
intConst = fmap IntConst intConst'
  where
    intConst' = (lexeme . try) ic
    ic = do
          x <- L.decimal -- parse a literal
          notFollowedBy letterChar -- fail if followed by a letter
          return x -- return the  result if we haven't failed

-- tryit "x + 5* y"
tryit :: String -> Either (ParseError (Token String) ()) AExpr
tryit  = parse expr "(--)"
