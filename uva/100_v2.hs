import Data.Char

cycleLength :: Int -> Int
cycleLength 1 = 1
cycleLength n
      | n `mod` 2 /= 0 = 1 + cycleLength (3 * n + 1)
      | otherwise = 1 + cycleLength (div n 2)

maxCycleLength :: Int -> Int -> Int
maxCycleLength m n
      | m == n = cycleLength n
      | m < n = if (cycleLength m) > (maxCycleLength (m + 1) n) then
                    cycleLength m
                else
                    maxCycleLength (m + 1) n
      | otherwise = 0

decimal :: [Int] -> Int
decimal [] = 0
decimal (x:[]) = x
decimal (x1:x2:xs) = decimal (10 * x1 + x2 : xs)

findChar :: Char -> [Char] -> Int
findChar c [] = -1
findChar c (x:xs)
       | c == x = 0
       | otherwise = 1 + findChar c xs

main = do
         l <- getLine
         let (xs, y:ys) = splitAt (findChar ' ' l) l
         putStr xs
         putChar ' '
         putStr ys
         putChar ' '
         putStrLn (show (
                         maxCycleLength
                         (decimal (map digitToInt xs))
                         (decimal (map digitToInt ys))
                       )
                 )
