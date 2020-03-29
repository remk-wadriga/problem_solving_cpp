#include <iostream>
#include <ctime>
#include "./helpers/IntegerHelper.cpp"
#include "./helpers/StringHelper.cpp"
#include "./helpers/ArrayHelper.cpp"
#include "./Chapter_3/Statistics.cpp"

int main()
{
    using namespace std;

    const int MAX_RESPONSE = 100000000;
    const int ARRAY_SIZE = 100000000;
    //int arr[ARRAY_SIZE] = {3, 7, 3, 9, 9, 1, 3, 9, 9, 9, 4, 3};
    int *arr = generateArr(ARRAY_SIZE, 1, MAX_RESPONSE);

    //quickSort(arr, ARRAY_SIZE);
    //printArr(arr, ARRAY_SIZE);

    srand(time(0));

    // max response 10 -        1000000: 0.022421, 10000000: 0.215316, 100000000: 2.14378
    // max response 100000000 - 1000000: 0.630104, 10000000: 0.969579, 100000000: 3.7683
    int mode = calculateMode(arr, MAX_RESPONSE, ARRAY_SIZE);

    // max response 10 -        1000000: 0.186542, 10000000: 2.11893, 100000000: 23.7281
    // max response 100000000 - 1000000: 0.25223, 10000000: 2.9346, 100000000: 33.6377
    //int mode = calculateModeUsingSort(arr, ARRAY_SIZE);

    cout << "Mode: " << mode << "\n";
    cout << "Runtime: " << clock() / 1000000.0 << "\n";

    return 0;
}