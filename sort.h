#ifndef SORT_H
#define SORT_H

#include "transactionlist.h"

class Sort
{
public:
    Sort(QList<Transaction*> l);
    virtual void sort() = 0;
    QList<Transaction*> getList();

protected:
    QList<Transaction*> sortList;
};

#endif // SORT_H
