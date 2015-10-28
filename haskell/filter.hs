import qualified Data.ByteString.Lazy as BL
import Data.Binary
import Data.Binary.Get

getMyBytes :: Get [Word8]
getMyBytes = do
	 empty <- isEmpty
	 if empty
	    then return []
	 else do b <- getWord8
	      	 bs <- getMyBytes
		 return (b:bs)

dataIO :: IO [Word8]
dataIO = do
       input <- BL.readFile "test.bin"
       return (runGet getMyBytes input)

main :: IO ()
main = do
     d <- dataIO
     putStr (show (length d))