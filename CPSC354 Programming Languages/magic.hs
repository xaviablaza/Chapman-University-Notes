module Magic where

noMagic m n = m : (noMagic n (m+n))
