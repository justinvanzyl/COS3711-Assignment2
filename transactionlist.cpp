#include "transactionlist.h"

TransactionList* TransactionList::instance = NULL;

TransactionList* TransactionList::getInstance() {
    if (instance == NULL) // initializes the instance if it hasnt been
        instance = new TransactionList;
    return instance;
}

void TransactionList::addTransaction(Transaction *t) {
    transactionList.append(t);
}

QList<Transaction*> TransactionList::returnList() {
    return transactionList;
}

TransactionList::TransactionList()
{}

TransactionList::~TransactionList() {
    qDeleteAll(transactionList);
    transactionList.clear();
}
