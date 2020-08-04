#ifndef EBAYBUCKS_H
#define EBAYBUCKS_H

#include <string>
#include "Auction.h"

class EBayBucks
{
    private:
    double earnedAward;

    public:
    EBayBucks();
    void addAuction(Auction a);
    double earnings() const;
    double issueCertificate();
};

#endif // !EBAYBUCKS_H
