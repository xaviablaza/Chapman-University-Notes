import Text.Megaparsec

data Lexeme
= Key Keyword
| Id String
| LParen
| RParen
| LBrace
| RBrace
| IntConst Integer
| BoolConst Boolean
| BoolOp
| ArithOp
| Relation

