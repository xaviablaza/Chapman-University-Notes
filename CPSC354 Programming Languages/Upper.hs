module Upper (ask,rep,askfile) where
  import Data.Char
  ask :: IO()
  ask = putStrLn "Enter string that you want to make uppercase?"
  rep :: String -> IO()
  rep ans = putStrLn $ map toUpper ans
  askfile :: IO()
  askfile = putStrLn "What file do you to be converted to uppercase?"
