#include <iostream>
#include "./helpers/IntegerHelper.cpp"
#include "./helpers/StringHelper.cpp"
#include "./helpers/ArrayHelper.cpp"

int main()
{
    using namespace std;

    const int ARRAY_SIZE = 10;
    int arr[ARRAY_SIZE] = {5, -8, -4, 0, 38, 70, -51, 85, 2, 49};

    bubbleSort(arr, ARRAY_SIZE);

    printArr(arr, ARRAY_SIZE);
    cout << "\n";

    return 0;
}