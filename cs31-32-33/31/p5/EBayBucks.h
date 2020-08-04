#ifndef EBAYBUCKS_H
#define EBAYBUCKS_H

#include <string>
#include "Auction.h"

class EbayBucks
{
    private:
    double earnedAward;

    public:
    EbayBucks();
    void addAuction(Auction a);
    double earnings() const;
    double issueCertificate();
};

#endif // !EBAYBUCKS_H
