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

    IntegersList list(100002);
    list.print();

    //int* arr = generateArr(ARRAY_SIZE, 0, 10);
    //cout << arr[0] << ", " << arr[1] << ", " << arr[2] << ", ..., " << arr[ARRAY_SIZE - 3] << ", " << arr[ARRAY_SIZE - 2] << ", " << arr[ARRAY_SIZE - 1] << "\n";
    cout << "Runtime: " << clock() / 1000000.0 << "\n";

    return 0;
}