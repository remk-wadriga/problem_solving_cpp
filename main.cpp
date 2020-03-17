#include <iostream>
#include <ctime>
#include "./helpers/IntegerHelper.cpp"
#include "./helpers/StringHelper.cpp"
#include "./helpers/ArrayHelper.cpp"

int main()
{
    using namespace std;

    const int size = 1000000;
    const int ARRAY_SIZE = size;
    int* arr = generateArr(ARRAY_SIZE, -size, size);

    srand(time(0));

    selectionSort(arr, ARRAY_SIZE); // 10 -> 45 (0.000828); 100 -> 4950 (0.000838); 1000 -> 499500 (0.001691); 10000 -> 49995000 (0.082824); 100000 -> 4999950000 (8.21922); 1000000 -> 499999500000 (857.421)
    //printArr(arr, ARRAY_SIZE);

    //bubbleSort(arr, ARRAY_SIZE); // 10 -> 45 (0.000823); 100 -> 4914 (0.000841); 1000 -> 497609 (0.003192); 10000 -> 49994880 (0.297736); 100000 -> 4999876847 (33.7419); 1000000 -> ()
    //printArr(arr, ARRAY_SIZE);

    //insertionSort(arr, ARRAY_SIZE); // 10 -> 34 (0.000821); 100 -> 2574 (0.000833); 1000 -> 253770 (0.002617); 10000 -> 24921357 (0.173482); 100000 -> 2493902983 (17.3207); 1000000 -> 249836674360 (1747.01)
    //printArr(arr, ARRAY_SIZE);
    //cout << "\n";

    cout << "Runtime: " << clock() / 1000000.0 << "\n";

    return 0;
}