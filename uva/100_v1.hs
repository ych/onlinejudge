import Data.String.Utils

main :: IO()
main = mapM_ (putStrLn . getResult . parseNum) . lines =<< getContents

parseNum :: String -> (String, Int, Int)
parseNum s =
    let [x, y] = splitWs s
    in (s, read x, read y)

getResult :: (String, Int, Int) -> String
getResult (s, x, y)
    | x <= y	= s ++ " " ++ (show (maxLength(x, y)))
    | otherwise	= s ++ " " ++ (show (maxLength(y, x)))

maxLength :: (Int, Int) -> Int
maxLength (x, y) = maximum ( map three_x_add_one [x..y] )

three_x_add_one :: Int -> Int
three_x_add_one 1 	= 1
three_x_add_one n
    | (mod n 2) == 0	= 1 + three_x_add_one (div n 2)
    | otherwise		= 1 + three_x_add_one (3*n+1)
