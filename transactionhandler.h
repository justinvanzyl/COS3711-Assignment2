#ifndef TRANSACTIONHANDLER_H
#define TRANSACTIONHANDLER_H

#include "transactionlist.h"

class TransactionHandler {
public:
    TransactionHandler();
    void makeDeposit(double a);
    void makeWithdrawal(double a);
    bool writeToFile();
    ~TransactionHandler();

private:
    TransactionList* transactionList;
};

#endif // TRANSACTIONHANDLER_H
