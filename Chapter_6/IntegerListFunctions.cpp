#include <iostream>

int calculateNegativeIntegers(IntegerList* list)
{
    int count = 0;
    /*AbstractListItem* item;
    while ((item = list->getNextItem()) != NULL) {
        if (((ListNode*)item)->data < 0) {
            count++;
        }
    }*/
    return count;
}

int calculateNegativeIntegersRecursive(IntegerList* list)
{
    /*AbstractListItem* item = list->getNextItem();
    if (item == NULL) {
        return 0;
    }
    return calculateNegativeIntegersRecursive(list) + (int)(((ListNode*)item)->data < 0);*/
    return 0;
}

int calculatePositiveIntegersSumRecursive(int* arr, int size)
{
    // Exit condition
    if (size <= 0) {
        return 0;
    }
    // Recursion
    return calculatePositiveIntegersSumRecursive(arr, size - 1) + (arr[size - 1] > 0 ? arr[size - 1] : 0);
}

int calculatePositiveIntegersSumRecursive(IntegerList* list)
{
    // Exit condition
    AbstractListItem* item = list->getNextItem();
    if (item == NULL) {
        return 0;
    }
    // Recursion
    return calculatePositiveIntegersSumRecursive(list) + (((IntegerItem*)item)->getVal() > 0 ? ((IntegerItem*)item)->getVal() : 0);
}

bool isEvenOneBytesCountRecursive(int* arr, int size)
{
    // Exit condition
    if (size <= 0) {
        return 0;
    }
    // Recursion
    return (isEvenOneBytesCountRecursive(arr, size - 1) + arr[size - 1]) % 2 == 0;
}

bool isEvenOneBytesCountRecursive(IntegerList* list, int count = 0)
{
    // Exit condition
    AbstractListItem* item = list->getNextItem();
    if (item == NULL) {
        return count % 2 == 0;
    }
    // Recursion
    return isEvenOneBytesCountRecursive(list, count + ((IntegerItem*)item)->getVal());
}

int countElemInArrayRecursive(int* arr, int size, int elem)
{
    // Exit condition
    if (size <= 0) {
        return 0;
    }
    // Recursion
    return countElemInArrayRecursive(arr, size - 1, elem) + (arr[size - 1] == elem ? 1 : 0);
}

int countElemInArrayRecursive(IntegerList* list, int elem)
{
    // Exit condition
    AbstractListItem* item = list->getNextItem();
    if (item == NULL) {
        return 0;
    }
    // Recursion
    return countElemInArrayRecursive(list, elem) + (((IntegerItem*)item)->getVal() == elem ? 1 : 0);
}


void demonstrateIntegersList()
{
    using namespace std;

    IntegerList list1;
    list1.add(-4);
    list1.add(1);
    list1.add(-2);
    list1.add(3);
    list1.add(-2);

    list1.print(" ");
    cout << countElemInArrayRecursive(&list1, -2) << "\n";

    /*const int ARRAY_SIZE = 5;
    int arr[ARRAY_SIZE] = {3, 1, 0, 3, -3};
    printArr(arr, ARRAY_SIZE, " ", false);
    cout << countElemInArrayRecursive(arr, ARRAY_SIZE, 3) << "\n";*/
}