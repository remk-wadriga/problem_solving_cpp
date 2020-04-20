#include <iostream>
#include <ctime>
#include "./helpers/IntegerHelper.cpp"
#include "./helpers/StringHelper.cpp"
#include "./helpers/ArrayHelper.cpp"
#include "./helpers/StatisticsHelper.cpp"
#include "./Chapter_3/Student.cpp"
#include "./Chapter_3/Encoder.cpp"

int main()
{
    using namespace std;

    const int ARRAY_SIZE = 10;

    //int* arr = generateArr(ARRAY_SIZE, 0, 10);
    int arr[ARRAY_SIZE] = {4, -4, 0, -3, -3, -5, 5, 2, -4, 3};

    // C++
    // Quick rep.   10: 34 (0.000842), 100: 1002 (0.000766),  1000: 16179 (0.000949),  10000: 218415 (0.00252),   100000: 3262318 (0.02272),   1000000: 37219208 (0.251853), 10000000: 449230113 (2.95154), 100000000: 5255599002 (33.7494)
    // Quick rep.   10: (0.000756), 100: (0.000825), 1000: (0.000941), 10000: (0.002445), 100000: (0.023346),  1000000: (0.25743), 10000000: (3.01938), 100000000: (34.4523)

    // PHP
    // Quick rep.   10: 34 (0.000842), 100: 1002 (0.000766),  1000: 00 (),  10000: 00 (),   100000: 00 (),   1000000: 00 (), 10000000: 00 (), 100000000: 00 ()
    // Quick rep.   10: (), 100: (), 1000: (), 10000: (), 100000: (),  1000000: (), 10000000: (), 100000000: ()

    quickSortReplaces(arr, ARRAY_SIZE);
    printArr(arr, ARRAY_SIZE, " ", false);

    //cout << arr[0] << ", " << arr[1] << ", " << arr[2] << ", ..., " << arr[ARRAY_SIZE - 3] << ", " << arr[ARRAY_SIZE - 2] << ", " << arr[ARRAY_SIZE - 1] << "\n";
    cout << "Runtime: " << clock() / 1000000.0 << "\n";

    return 0;
}