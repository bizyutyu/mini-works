-- ランダムアクセス
main = do
line1 <- getLine
line2 <- getLine
let [_, m] = map read (words line1) :: [Int]
    output = (words line2) !! (m - 1)
putStr output