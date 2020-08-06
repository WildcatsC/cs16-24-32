#include <iostream>
#include "Auction.h"
using namespace std;

Auction::Auction(string description, double minprice){
    mDescription = description;
    mMinimumPrice = minprice;
    mCurrentBid = 0;
    mTotalNumberOfBids = 0;
    mAuctionIsOpen = false;
}

void Auction::openAuction(){
    mAuctionIsOpen = true;
}

bool Auction::bid(double amount){
    if(mAuctionIsOpen == true){
        if(amount > mCurrentBid){
            mCurrentBid = amount;
            mTotalNumberOfBids++;
            return true;
        }
    }
    return false;
}

int Auction::numberOfBids() const{
    return mTotalNumberOfBids;
}

void Auction::closeAuction(){
    mAuctionIsOpen = false;
}

bool Auction::wasSuccessful() const{
    if(mCurrentBid > mMinimumPrice && mAuctionIsOpen == false)
        return true;
    return false;
}

double Auction::winningBid() const{
    if(this->wasSuccessful()==true)
        return mCurrentBid;
    return -1.0;
}

string Auction::getDescription() const{
    return mDescription;
}

