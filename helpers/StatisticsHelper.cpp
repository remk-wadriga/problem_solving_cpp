#include <iostream>
// #include "./ArrayHelper.cpp"

int getMode(int arr[], const int maxResponse, const int size)
{
    int *histogram = createHistogram(arr, maxResponse, size);

    int maxElem = maxElement(histogram, maxResponse);
    return indexOf(maxElem, histogram, maxResponse) + 1;

    return 0;
}

int getMedian(int arr[], const int size)
{
    quickSort(arr, size);
    return arr[size / 2 - 1 + size % 2];
}