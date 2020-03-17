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

void selectionSort(int arr[], const int size)
{
    using namespace std;
    int val, check, nextIndex, minIndex;
    int maxIndex = size - 1;
    long long steps = 0;

    for (int j = 0; j < maxIndex; j++) {
        minIndex = j;
        for (int i = j + 1; i < size; i++) {
            steps++;
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }
        if (minIndex != j) {
            val = arr[minIndex];
            arr[minIndex] = arr[j];
            arr[j] = val;
        }
    }

    cout << steps << "\n";
}

void bubbleSort(int arr[], const int size)
{
    using namespace std;
    int nextVal, check, nextIndex, maxIndex;
    long long steps = 0;

    for (int j = 1; j < size; j++) {
        check = 0;
        maxIndex = size - j;
        for (int i = 0; i < maxIndex; i++) {
            steps++;
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

    cout << steps << "\n";
}

void insertionSort(int arr[], const int size)
{
    using namespace std;
    int val, prevIndex, prevVal;
    long long steps = 0;

    for (int j = 1; j < size; j++) {
        val = arr[j];
    	for (int i = j; i > 0; i--) {
    	    steps++;
    	    prevIndex = i - 1;
    	    prevVal = arr[prevIndex];
    	    if (val >= prevVal) {
    	        break;
    	    }
    	    arr[prevIndex] = arr[i];
    	    arr[i] = prevVal;
    	}
    }

    cout << steps << "\n";
}