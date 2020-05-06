#include <iostream>
#include "./IntegerList.cpp"

int calculateNegativeIntegers(IntegerList* list)
{
    int count = 0;
    AbstractListItem* item;
    while ((item = list->getNextItem()) != NULL) {
        if (((ListNode*)item)->data < 0) {
            count++;
        }
    }
    return count;
}

int calculateNegativeIntegersRecursive(IntegerList* list)
{
    AbstractListItem* item = list->getNextItem();
    if (item == NULL) {
        return 0;
    }
    return calculateNegativeIntegersRecursive(list) + (int)(((ListNode*)item)->data < 0);
}

void demonstrateIntegersList()
{
    using namespace std;

    IntegerList list1;
    list1.add(-4);
    list1.add(5);
    list1.add(-1);
    list1.add(8);
    list1.add(-5);
    list1.add(0);

    list1.print();
    cout << calculateNegativeIntegersRecursive(&list1) << "\n";
}