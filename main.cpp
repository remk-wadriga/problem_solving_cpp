#include <iostream>
#include <ctime>
#include "./helpers/IntegerHelper.cpp"
#include "./helpers/StringHelper.cpp"
#include "./helpers/ArrayHelper.cpp"
#include "./helpers/StatisticsHelper.cpp"
#include "./Chapter_3/Statistics.cpp"

int main()
{
    using namespace std;

    const int MAX_RESPONSE = 100;
    const int ARRAY_SIZE = 10;
    //int arr[ARRAY_SIZE] = {3, 7, 3, 9, 9, 1, 3, 9, 9, 9, 4, 3};
    int *arr = generateArr(ARRAY_SIZE, 1, MAX_RESPONSE);

    quickSort(arr, ARRAY_SIZE);
    printArr(arr, ARRAY_SIZE);

    srand(time(0));

    int median = getMedian(arr, ARRAY_SIZE);

    cout << "Median: " << median << "\n";
    cout << "Runtime: " << clock() / 1000000.0 << "\n";

    return 0;
}