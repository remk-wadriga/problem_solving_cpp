#include <iostream>

/**
*# Найти "моду" массива чисел: т. е., наиболее часто встречающийся элемент.
*# План:
* 1. Отсортировать массив, чтобы элементы шли подряд +
* 2. Найти способ определения конца последовательности одинаковых чисел +
* 3. Посчитать последовательно количество всех чисел, чтобы определить наибольшую последовательность +
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

int calculateMode(int arr[], const int maxResponse, const int size)
{
    using namespace std;
    int *histogram = createHistogram(arr, maxResponse, size);

    int maxElem = maxElement(histogram, maxResponse);
    return indexOf(maxElem, histogram, maxResponse) + 1;

    return 0;
}