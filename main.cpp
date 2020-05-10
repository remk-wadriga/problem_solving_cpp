#include <iostream>
#include <ctime>
#include "./helpers/ArrayHelper.cpp"
#include "./lib/TreeList.cpp"
#include "./lib/IntegerList.cpp"
#include "./Chapter_6/IntegerListFunctions.cpp"

int main()
{
    using namespace std;

    const int ARRAY_SIZE = 5;
    int* arr = generateArr(ARRAY_SIZE, 0, 10);
    /*printArr(arr, ARRAY_SIZE);
    cout << arraySum(arr, ARRAY_SIZE) << "\n";*/

    demonstrateIntegersList();

    //int* arr = generateArr(ARRAY_SIZE, 0, 10);
    //cout << arr[0] << ", " << arr[1] << ", " << arr[2] << ", ..., " << arr[ARRAY_SIZE - 3] << ", " << arr[ARRAY_SIZE - 2] << ", " << arr[ARRAY_SIZE - 1] << "\n";
    cout << "Runtime: " << clock() / 1000000.0 << "\n";

    return 0;
}