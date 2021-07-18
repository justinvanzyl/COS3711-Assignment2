#ifndef TRANSACTIONLIST_H
#define TRANSACTIONLIST_H

#include "transaction.h"

class TransactionList
{

public:
    static TransactionList* getInstance();
    void addTransaction(Transaction* t);
    QList<Transaction*> returnList();
    ~TransactionList();

private:
    TransactionList();
    static TransactionList* list;
    QList<Transaction*> transactionList;
};

#endif // TRANSACTIONLIST_H
