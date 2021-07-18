#ifndef TRANSACTIONLIST_H
#define TRANSACTIONLIST_H

#include "transaction.h"

class TransactionList {
public:
    static TransactionList* getInstance(); // getter for TransactionList instance
    void addTransaction(Transaction *t); // appends transactions to the list
    QList<Transaction*> returnList();   // getter for the list
    ~TransactionList();

private:
    TransactionList(); // private constructor
    static TransactionList* instance; // single instance of TransactionList
    QList<Transaction*> transactionList; // list of transactions
};

#endif // TRANSACTIONLIST_H
