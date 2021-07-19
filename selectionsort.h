#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "sort.h"

class SelectionSort : public Sort {
public:
    SelectionSort(QList<Transaction*> l);
    void sort();

private:
    int minLocation(int first, int last);
};

#endif // SELECTIONSORT_H
