Furthermore,

<integer literal> is a non-empty string of decimal digits.
We will need to figure out how to parse quoted strings.
we will need a definition of comments. Let’s simply borrow from C++. So
Text from // to end of line is ignored
Text between /* and */ is ignored
Abstract Syntax in Haskell
The following Haskell code defines inductive data types that almost correctly correspond to the abstract syntax of our language.

type Program = [Statement] -- a program is a list of statements

data Statement
  = Assignment Identifier Expression
  | If Condition Statement Statement
  | While Condition Statement
  | Msg String
  | Msg String
  | Print Expression
  | Println Expression
  | Read Identifier
  | Skip
  | Block Program
  | Comment

type Identifer = String

-- This is not correct
data Condition
  = BoolConst Bool
  | Not Condition
  | BoolBinOp Condition Condition
  | Test Comparison Expression Expression

data BoolBinOp
  = And
  | Or

data Comparison
  = Greater
  | GreaterEq
  | Less
  | LessEqual
  | Equal
  | NEqual

-- This is not correct
data Expression
  = Var Identifier
  | IntConst Integer
  | Unary UnOp Expression
  | BinExpression BinOp Expression Expression

data Expression
  = Term
  | Expression AddOP Term

data Term
  = Factor
  | Term MulOP Factor

data factor
  = Var Identifier
  | IntConst Integer
  | Expression

data UnOp = Neg

data BinOp
  = Plus
  | Minus
  | Times
  | Divide
  | Mod

interpBinop :: BinOP -> (Integer -> Integer -> Integer)
interpBinop Plus = (+)
interpBinop MInus = (-)
interpBinop Times = (*)
interpBinop Divide = div
interpBinop Mod = swap mod

toBinSymbol :: BinOp -> String
toBinSymbol Plus = "+"
toBinSymbol Minus = "-"
toBinSymbol Times = "*"
toBinSymbol Divide = "/"
toBinSymbol Mod = "%"

toUnSymbol :: UnOp -> String
toUnSymbol Neg = "-"

unparse :: Expression -> String
unparse (Var id) = id
unparse (IntConst val) = show val
unparse (Unary op exp) = toUnSymbol op ++ " " ++ unparse exp
unparse (Binary op exp1 exp2) = "(" ++ (unparse exp1) ++ " " ++ toBinSymbol op ++ " " ++ unparse exp2 ++ ")"

test1 = Binary Times (Binary Times (Var "x") (IntConst 5)) (IntConst 7)
test2 = Unary Neg (Var "x")

eval :: Dictionary -> Expression -> Integer
eval dict (var id) = lookup dict id
eval dict (IntConst val) = Just val
eval dict Unary Neg exp = - ( eval dict exp )
eval dict Binary op exp1 exp2 =
  (interpBinop op) <$> eval dict exp1 <*> eval dict exp2


{--

x = 1;
while x > 0 {
  println x;
  x = x - 1
}

--}

example :: Program
example = [ Assignment "x" (IntConst 10),
            While (Test (Greater (Var "x") (IntConst 0))
              (Block" "
                [ Println (Var "x"),
                  Assignment "x" (BinExpression Minus (Var "x") (IntConst 1))
                ]
              )
          ]
