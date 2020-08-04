#include <iostream>
#include "Auction.h"
using namespace std;

Auction::Auction(string description, double minprice){
    mDescription = description;
    mMinimumPrice = minprice;
    cout << "草尼玛" << endl;
}

void Auction::openAuction(){

}

bool Auction::bid(double amount){
    return false;
}

int Auction::numberOfBids() const{
    return 0;
}

void Auction::closeAuction(){

}

bool Auction::wasSuccessful() const{
    return false;
}

double Auction::winningBid() const{
    return 0;
}

string Auction::getDescription() const{
    return "";
}


