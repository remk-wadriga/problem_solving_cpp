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

bool isEvenOneBytesCountRecursive(int* arr, int size)
{
    // Exit condition
    if (size <= 0) {
        return 0;
    }
    // Recursion
    return (isEvenOneBytesCountRecursive(arr, size - 1) + arr[size - 1]) % 2 == 0;
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

    /*list1.print();
    cout << calculateNegativeIntegersRecursive(&list1) << "\n";*/

    const int ARRAY_SIZE = 5;
    //int* arr = generateArr(ARRAY_SIZE, 0, 1);
    int arr[ARRAY_SIZE] = {0, 1, 0, 1, 0};
    printArr(arr, ARRAY_SIZE, " ", false);
    cout << isEvenOneBytesCountRecursive(arr, ARRAY_SIZE) << "\n";
}