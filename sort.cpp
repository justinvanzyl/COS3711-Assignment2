#include "sort.h"

Sort::Sort(QList<Transaction*> l) {
    sortList.clear();
    for(int i = 0; i < l.size(); i++)
        sortList.append(l.at(i));
}

QList<Transaction*> Sort::getList() {
    return sortList;
}
