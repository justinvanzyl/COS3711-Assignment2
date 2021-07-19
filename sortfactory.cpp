#include "sortfactory.h"

SortFactory::SortFactory() {}

Sort* SortFactory::setSort(QString type, QList<Transaction*> l) {
    if(type == "Selection")
        return new SelectionSort(l);
    else if(type == "Insertion")
        return new InsertionSort(l);
    else
        return NULL;
}
