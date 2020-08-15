all: Auction.cpp EBayBucks.cpp main.cpp
	g++ -c Auction.cpp
	g++ -c EBayBucks.cpp
	g++ -c main.cpp

test: Auction.o EBayBucks.o main.o
	g++ Auction.o EBayBucks.o main.o -o Test
	./Test


