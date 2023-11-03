main = do
  let n :: Int
      x :: Double
      c :: Char
      na1 :: [Int]
      na2 :: [Int]
      n0 :: Int
      n1 :: Int
      n2 :: Int
      n3 :: Int
      n4 :: Int
      n5 :: Int
      n6 :: Int
      n7 :: Int

      n0 = sizeOf n
      n1 = sizeOf x
      n2 = sizeOf c
      n3 = sizeOf na1
      n4 = sizeOf na2
      n5 = sizeOf (na1 !! 0)
      n6 = sizeOf na1 `div` sizeOf (na1 !! 0)
      n7 = sizeOf na2 `div` sizeOf (na2 !! 0)

  putStrLn $ "int:" ++ show n0
  putStrLn $ "double: " ++ show n1
  putStrLn $ "char:" ++ show n2
  putStrLn $ "int*10:" ++ show n3
  putStrLn $ "int*?:" ++ show n4
  putStrLn $ "int:" ++ show n5
  putStrLn $ "na1:" ++ show n6
  putStrLn $ "na2:" ++ show n7
