#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "sort.h"

class InsertionSort : public Sort
{
public:
    InsertionSort(QList<Transaction*> l);
    void sort();
};

#endif // INSERTIONSORT_H
