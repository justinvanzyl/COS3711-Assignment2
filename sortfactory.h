#ifndef SORTFACTORY_H
#define SORTFACTORY_H

#include "sort.h"

class SortFactory
{
public:
    SortFactory();
    Sort* sort(QString type, QList<Transaction*> l);
};

#endif // SORTFACTORY_H
