module RecAsFP where

fact1 :: Integer -> Integer
fact1 0 = 1
fact1 m = m * fact1(m-1)
