#include <iostream>

void fillArr(int arr[], const int size, const int min = 0, const int max = 1000)
{
    int val;
    for (int i = 0; i < size; i++) {
    	arr[i] = min + rand() % (max - min);
    }
}

int* generateArr(const int size, const int min = 0, const int max = 1000)
{
    int* arr = new int[size];
    fillArr(arr, size, min, max);
    return arr;
}

void printArr(int arr[], const int size)
{
    using namespace std;
    int lastIndex = size - 1;

    cout << "[\n";
    for (int i = 0; i < size; i++) {
        cout << "    " << i << " => " << arr[i];
        if (i < lastIndex) {
            cout << ",";
        }
        cout << "\n";
    }
    cout << "]";
}

void bubbleSort(int arr[], const int size)
{
    using namespace std;
    int nextVal, check, nextIndex, maxIndex;
    for (int j = 1; j < size; j++) {
        check = 0;
        maxIndex = size - j;
        for (int i = 0; i < maxIndex; i++) {
        	nextIndex = i + 1;
        	nextVal = arr[nextIndex];
        	if (arr[i] > nextVal) {
        	    arr[nextIndex] = arr[i];
        	    arr[i] = nextVal;
        	    check = 1;
        	}
        }
        if (check == 0) {
            break;
        }
    }
}