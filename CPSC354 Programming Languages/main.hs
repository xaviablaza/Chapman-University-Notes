module Main where
  import Data.Char
  import Upper
  main :: IO ()
  main = do
    ask
    message <- getLine
    rep message
    askfile
    contents <- readFile "words.txt"
    rep contents
