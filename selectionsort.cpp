#include "selectionsort.h"

SelectionSort::SelectionSort(QList<Transaction*> l) : Sort(l) {}

void SelectionSort::sort() {
    int minIndex;
    for (int loc = 0; loc < sortList.size()-1; loc++) {
        minIndex = minLocation(loc, sortList.size()-1);
        sortList.swapItemsAt(loc, minIndex);
    }
}

int SelectionSort::minLocation(int first, int last) {
    int minIndex = first;
    for (int loc = first+1; loc <= last; loc++)
        if (sortList.at(loc)->getAmount() < sortList.at(minIndex)->getAmount())
            minIndex = loc;
    return minIndex;
}
