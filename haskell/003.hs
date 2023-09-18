-- FiggBuzzのパターンマッチ
main = do
n <- getLine
mapM (putStrLn . fizzBuzz) [1..(read n)]
  where fizzBuzz n
          | n `mod` 3 == 0 && n `mod` 5 == 0 = "Fizz Buzz"
          | n `mod` 3 == 0 = "Fizz"
          | n `mod` 5 == 0 = "Buzz"
          | otherwise = show n
                      