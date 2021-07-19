#include "sortfactory.h"
#include "selectionsort.h"
#include "insertionsort.h"

SortFactory::SortFactory() {}

Sort *SortFactory::sort(QString type, QList<Transaction *> l) {
    if(type == "Selection")
        return new SelectionSort(l);
    else if(type == "Insertion")
        return new InsertionSort(l);
    else
        return NULL;
}
