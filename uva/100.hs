import Data.String.Utils

main :: IO()
main = mapM_ (putStrLn . getResult . parseNum) . lines =<< getContents

parseNum :: String -> (Int, Int)
parseNum = toTuple . splitWs

toTuple :: [String] -> (Int, Int)
toTuple [x, y] = (read x, read y)

getResult :: (Int, Int) -> String
getResult (x, y)
        | x <= y        = (show x) ++ " " ++ (show y) ++ " " ++ (show (maxLength(x, y)))
        | otherwise     = (show x) ++ " " ++ (show y) ++ " " ++ (show (maxLength(y, x)))

maxLength :: (Int, Int) -> Int
maxLength (x, y) = maximum ( map (three_x_add_one 0) [x..y] )

three_x_add_one :: Int -> Int -> Int
three_x_add_one count n
	| n == 1		= count + 1
	| n `mod` 2 == 0	= three_x_add_one (count+1) (n `div` 2)
	| otherwise		= three_x_add_one (count+1) (3*n+1)

