CC=g++
winCC=x86_64-w64-mingw32-g++
winCFLAGS=-static
CFLAGS=-Wall
A=TicTacToe
default:
	$(CC) -o $(A) $(A).cpp $(CFLAGS)
windows:
	$(winCC) -o $(A).exe $(A).cpp $(winCFLAGS)
run:
	$(CC) -o $(A) $(A).cpp $(CFLAGS) && ./$(A)
