#include "Auction.h"
#include "EBayBucks.h"
#include <iostream>
#include <cassert>
#include <string>
using namespace std;

int main(){
    cout << "start testing now" << endl;
               // sample test code 

    Auction* auc;
    auc = new Auction("2th Generation iPad Pro", 50.00);
    //Auction auction( "4th Generation iPod", 50.00 );

    EBayBucks bucks;

    auc->openAuction();
    auc->closeAuction();
    assert(auc->winningBid()== -1.0);

    auc->openAuction();
    assert(auc->bid(-1) == false);
    assert(auc->bid(0) == false);
    assert(auc->bid(5) == true);
    assert(auc->bid(1000000) == true);
    assert(auc->numberOfBids() == 2);
    assert(auc->bid(1000000.0) == false);
    assert(auc->numberOfBids() == 2);
    assert(auc->wasSuccessful() == false);
    assert(auc->winningBid() == -1);
    auc->closeAuction();
    assert(auc->wasSuccessful() == true);
    assert(auc->winningBid() == 1000000.0);
    assert(bucks.earnings() == 0);
    assert(bucks.issueCertificate() == 0);
    assert(bucks.issueCertificate() == 0);
    assert(bucks.earnings() == 0);

    delete auc;

    Auction auction( "4th Generation iPod", 50.00 );

           assert( auction.numberOfBids( ) == 0 );
           assert( auction.wasSuccessful( ) == false );
           assert( auction.getDescription( ) == "4th Generation iPod" );
           assert( std::to_string( auction.winningBid( ) ) == "-1.000000" );

           // bids don't count if the auction isn't open...
           assert( auction.bid( 100.00 ) == false );
           assert( auction.bid( 200.00 ) == false );
           assert( auction.bid( 300.00 ) == false );
           assert( auction.numberOfBids( ) == 0 );
           assert( auction.wasSuccessful( ) == false );
           assert( std::to_string( auction.winningBid( ) ) == "-1.000000" );

           auction.openAuction( );

           // an auction is not successful if the bids are too low...
           assert( auction.bid( -50.00 ) == false );   // negative bids are ignored
           assert( auction.bid( 1.00 ) == true );
           assert( auction.bid( 2.00 ) == true );
           assert( auction.bid( 3.00 ) == true );
           assert( auction.bid( 1.50 ) == false );     // bids lower than the currentBid value are ignored
           assert( auction.numberOfBids( ) == 3 );
           assert( auction.wasSuccessful( ) == false );
        //    assert( std::to_string( auction.winningBid( ) ) == "-1.000000" );
        cout << std::to_string(auction.winningBid()) << endl;
        cout << auction.winningBid() << endl;
        assert(auction.winningBid() == -1);

           // an auction must be closed to be deemed successful
           assert( auction.bid( 100.00 ) == true );
           assert( auction.numberOfBids( ) == 4 );
           assert( auction.wasSuccessful( ) == false );

           auction.closeAuction( );
           assert( auction.wasSuccessful( ) == true );
           assert( std::to_string( auction.winningBid( ) ) == "100.000000" );

           // bids don't count if the auction is closed...
           assert( auction.bid( 500.00 ) == false );
           assert( auction.bid( 600.00 ) == false );
           assert( auction.numberOfBids( ) == 4 );

           assert( std::to_string( bucks.earnings( ) ) == "0.000000" );
           assert( std::to_string( bucks.issueCertificate( ) ) == "0.000000" );

           bucks.addAuction( auction );
           assert( std::to_string( bucks.earnings( ) ) == "1.000000" );
           assert( std::to_string( bucks.issueCertificate( ) ) == "1.000000" );
           // once a certificate is issued, the earned award gets reset to zero
           assert( std::to_string( bucks.earnings( ) ) == "0.000000" );

           Auction a( "unsuccessful auction", 10000.00 );
           a.openAuction( );
           assert( a.bid( 100.00 ) == true );
           a.closeAuction( );
           assert( a.wasSuccessful( ) == false );

           // unsuccessful auctions don't raise the earned award
           bucks.addAuction( a );
           assert( std::to_string( bucks.earnings( ) ) == "0.000000" );

    Auction bike( "10 speed bicycle", 50.00 );
bike.openAuction();
bike.bid( 100.00 );
bike.closeAuction();  // successful auction

Auction ipod( "Apple iPod", 50.00 );
ipod.openAuction();
ipod.closeAuction();  // unsuccessful auction

Auction printer( "HP Laserjet 500xl", 159.00 );
printer.openAuction();
printer.bid( 100.00 );
printer.bid( 125.00 );
printer.closeAuction();   // unsuccessful auction

// your coding problem is here...
assert( bike.allSold( bike, ipod, printer ) == false );
assert( bike.allSold( ipod, printer, ipod ) == false );
assert( bike.allSold( bike, bike, bike ) == true );

int k = 120;
double b = 120.0;
cout << "a: " << std::to_string(k) << endl;
cout << "b: " << std::to_string(b) << endl;
        cout << "all tests passed!" << endl;

    return 0;
}