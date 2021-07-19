#include "insertionsort.h"

InsertionSort::InsertionSort(QList<Transaction*> l) : Sort(l) {}

void InsertionSort::sort() {
    int firstOutOfOrder, location;
    Transaction *temp;
    for (firstOutOfOrder = 1; firstOutOfOrder < sortList.size(); firstOutOfOrder++)
        if (sortList[firstOutOfOrder]->getAmount() < sortList[firstOutOfOrder-1]->getAmount()) {
            temp = sortList[firstOutOfOrder];
            location = firstOutOfOrder;
            do {
                sortList[location] = sortList[location-1];
                location--;
            } while (location>0 && sortList[location-1]->getAmount() > temp->getAmount());
            sortList[location] = temp;
        }
}
