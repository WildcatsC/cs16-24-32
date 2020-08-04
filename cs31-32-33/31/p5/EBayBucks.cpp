#include <iostream>
#include "EBayBucks.h"
using namespace std;

EBayBucks::EBayBucks(){
    earnedAward = 0;
}

void EBayBucks::addAuction(Auction a){
    if(a.winningBid()!=-1)
        earnedAward+=0.01*a.winningBid();
}

double EBayBucks::earnings() const{
    return earnedAward;
}

double EBayBucks::issueCertificate(){
    double issued = earnedAward;
    earnedAward = 0;
    return issued;
}
