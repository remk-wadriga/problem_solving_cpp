#include <iostream>

/**
*# Найти "моду" массива чисел: т. е., наиболее часто встречающийся элемент.
*# План:
* 1. Отсортировать массив, чтобы элементы шли подряд +
* 2. Найти способ определения конца последовательности одинаковых чисел
* 3. Посчитать последовательно количество всех чисел, чтобы определить наибольшую последовательность
*/
int calculateMode(int arr[], const int size)
{
    using namespace std;

    // 1. sort an array
    selectionSort(arr, size);

    // 2, 3. Find the longest sequence
    int currentCount = 1, maxCount = 0;
    int currentElement = arr[0];
    int mode = currentElement;
    for (int j = 1; j < size; j++) {
        if (currentElement == arr[j]) {
            currentCount++;
        } else {
            currentCount = 1;
            currentElement = arr[j];
        }
        if (currentCount > maxCount) {
            maxCount = currentCount;
            mode = currentElement;
        }

    }

    return mode;
}