#ifndef TRANSACTIONHANDLER_H
#define TRANSACTIONHANDLER_H

#include "transactionlist.h"
#include <QDomDocument>

// Handler class to manage the transaction list & keep it independent of UI:
class TransactionHandler {
public:
    // constructor:
    TransactionHandler();

    // functions to handle instructions from UI:
    void transact(QString tt, double a);
    bool toFile();

    //destructor:
    ~TransactionHandler();

private:
    TransactionList* transactionList; // TransactionList pointer data member
};

#endif // TRANSACTIONHANDLER_H
