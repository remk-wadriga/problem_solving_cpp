#include <iostream>

/**
 * max response 10 -        1000000: 0.186542, 10000000: 2.11893, 100000000: 23.7281
 * max response 100000000 - 1000000: 0.25223, 10000000: 2.9346, 100000000: 33.6377
*/
int calculateModeUsingSort(int *arr, const int size)
{
    using namespace std;

    // 1. sort an array
    quickSort(arr, size);

    // 2, 3. Find the longest sequence
    int lastCount = 1, maxCount = 1;
    int lastElement = arr[0];
    int mode = lastElement;
    for (int j = 1; j < size; j++) {
        if (lastElement == arr[j]) {
            lastCount++;
        } else {
            lastCount = 1;
            lastElement = arr[j];
        }
        if (lastCount > maxCount) {
            maxCount = lastCount;
            mode = lastElement;
        }
    }

    return mode;
}

/**
 * max response 10 -        1000000: 0.022421, 10000000: 0.215316, 100000000: 2.14378
 * max response 100000000 - 1000000: 0.630104, 10000000: 0.969579, 100000000: 3.7683
*/
int calculateMode(int arr[], const int maxResponse, const int size)
{
    int *histogram = createHistogram(arr, maxResponse, size);

    int maxElem = maxElement(histogram, maxResponse);
    return indexOf(maxElem, histogram, maxResponse) + 1;

    return 0;
}