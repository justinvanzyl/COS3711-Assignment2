#include "transactionlist.h"

TransactionList* TransactionList::list = NULL;

TransactionList* TransactionList::getInstance() {
    if (list == NULL)
        list = new TransactionList;
    return list;
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
