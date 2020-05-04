#include <iostream>
#include <ctime>
#include "./structures/NumInList.cpp"
#include "./helpers/IntegerHelper.cpp"
#include "./helpers/StringHelper.cpp"
#include "./helpers/ArrayHelper.cpp"
#include "./helpers/StatisticsHelper.cpp"
#include "./Chapter_5/StudentFunctions.cpp"
#include "./lib/list/AbstractList.cpp"
#include "./Chapter_6/IntegersList.cpp"

int main()
{
    using namespace std;

    const int ARRAY_SIZE = 5;
    int* arr = generateArr(ARRAY_SIZE, 0, 10);
    /*printArr(arr, ARRAY_SIZE);
    cout << arraySum(arr, ARRAY_SIZE) << "\n";*/

    IntegersList list1(123);
    IntegersList list2(78);

    IntegerItem* num1 = new IntegerItem(1);
    IntegerItem* num2 = new IntegerItem(2);
    IntegerItem* num3 = new IntegerItem(3);
    IntegerItem* num4 = new IntegerItem(4);
    IntegerItem* num5 = new IntegerItem(5);
    IntegerItem* num6 = new IntegerItem(6);
    IntegerItem* num7 = new IntegerItem(7);

    list1.print();
    //list1.addFirstList(&list2);
    //list1.addAfterList(&list2, 1);
    //list1.addLastList(&list2);
    list1 = list2;
    list2.addLastItem(new IntegerItem(3));
    cout << "-------------------" << "\n";
    list1.print();
    list2.print();
    cout << list2.getLastItem()->toString() << "\n";


    //int* arr = generateArr(ARRAY_SIZE, 0, 10);
    //cout << arr[0] << ", " << arr[1] << ", " << arr[2] << ", ..., " << arr[ARRAY_SIZE - 3] << ", " << arr[ARRAY_SIZE - 2] << ", " << arr[ARRAY_SIZE - 1] << "\n";
    cout << "Runtime: " << clock() / 1000000.0 << "\n";

    return 0;
}