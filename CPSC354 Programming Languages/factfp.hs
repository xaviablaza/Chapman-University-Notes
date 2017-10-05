factRec :: (Integer -> Integer) -> (Integer -> Integer(
factRec f 0 = 1
factRec f m = m * f (m-1)

factFP = factRec factFP

-- Come back ready to explain how this piece of code evaluates correctly
-- factFP 4 is 4 factorial which is 24, it gets the right answer, but how does it do that
-- What is lazy evaluation?
