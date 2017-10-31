import Text.Megaparsec -- the main combinator library
import Text.Megaparsec.Char -- various basic parsers for characters
import qualified Text.Megaparsec.Char.Lexer as L -- This avoids name clashes with Prelude.

type Parser = Parsec () String

-- space1 is a parser from Text.Megaparsec.Char that will consume one or more whitespaces
-- L.space is a combinator that combines its first argument to consume space characters and its 2nd and 3rd arguments to specify how comments are formed.
-- L.skipLineComment matches its 1st argument then ignores everything to end of line
-- L.skipblockComment matches begin- and end-comment strings and ignores everything between

spaceConsumer :: Parser ()
spaceConsumer = L.space space1 lineCmnt blockCmnt
  where
    -- how you want comments to start
    lineCmnt  = L.skipLineComment "//"
    -- how you want block comments to start and end
    blockCmnt = L.skipBlockComment "/*" "*/"

-- Define a wrapper that consumes space after a parser
lexeme :: Parser a -> Parser a
lexeme = L.lexeme spaceConsumer

keywords = ["while", "if", "then", "else", "print", "printmsg","read"]

identifier :: Parser String
identifier = (lexeme . try) $ (:) <$> letterChar <*> many alphaNumChar

data MoBettaToken = Identifier String | Constant Integer

identifier' :: Parser MoBettaToken
identifier' = fmap Identifier identifier

intConst :: Parser Integer
intConst = (lexeme . try) ic
  where
    ic = do
      x <- L.decimal -- parse a literal
      notFollowedBy letterChar -- fail if followed by a letter
      return x -- return the  result if we haven't failed

intConst' :: Parser MoBettaToken
intConst' = fmap Constant intConst
