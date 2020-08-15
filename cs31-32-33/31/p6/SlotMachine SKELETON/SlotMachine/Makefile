
all: Bank.cpp Screen.cpp PayTable.cpp SlotMachine.cpp RandomNumber.cpp main.cpp
	g++ -std=c++11 -c Bank.cpp Screen.cpp PayTable.cpp SlotMachine.cpp RandomNumber.cpp main.cpp

test: Bank.o Screen.o PayTable.o SlotMachine.o RandomNumber.o main.o 
	g++ -std=c++11 Bank.o Screen.o PayTable.o SlotMachine.o RandomNumber.o main.o -o main && ./main

clear:
	rm *.o && rm main