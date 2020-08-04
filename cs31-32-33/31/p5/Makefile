all: Auction.cpp EBayBucks.cpp Test.cpp
	g++ -c Auction.cpp
	g++ -c EBayBucks.cpp
	g++ -c Test.cpp

test: Auction.o EBayBucks.o Test.o
	g++ Auction.o EBayBucks.o Test.o -o Test
	./Test


