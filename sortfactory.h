#ifndef SORTFACTORY_H
#define SORTFACTORY_H

#include "sort.h"
#include "selectionsort.h"
#include "insertionsort.h"

class SortFactory
{
public:
    SortFactory();
    Sort* setSort(QString type, QList<Transaction*> l);
};

#endif // SORTFACTORY_H
