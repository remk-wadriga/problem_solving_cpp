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

int* createArray(const int size, int elem)
{
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
    	arr[i] = elem;
    }
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

int indexOf(int elem, int arr[], const int size)
{
    for (int i = 0; i < size; i++) {
    	if (elem == arr[i]) {
    	    return i;
    	}
    }
    return -1;
}

// <-- Sorting algorithms -->

// Selection results:
    // C++:
        // With iteration calculation:
            // Bubbles.     10: 45 (0.000823), 100: 4914 (0.000841), 1000: 497609 (0.003192), 10000: 49994880 (0.297736), 100000: 4999876847 (33.7419), 1000000: 499999477209 (3426.62)
            // Inserts.     10: 34 (0.000821), 100: 2574 (0.000833), 1000: 253770 (0.002617), 10000: 24921357 (0.173482), 100000: 2493902983 (17.3207), 1000000: 249836674360 (1747.01)
            // Selection.   10: 45 (0.000828), 100: 4950 (0.000838), 1000: 499500 (0.001691), 10000: 49995000 (0.082824), 100000: 4999950000 (8.21922), 1000000: 499999500000 (857.421)
        // Without iteration calculation:
            // Bubbles.     10: 45 (0.000808), 100: 4914 (0.001138), 1000: 497609 (0.014371), 10000: 49994880 (0.306641), 100000: 4999876847 (34.1137), 1000000: 499999477209 (3465.76)
            // Inserts.     10: 34 (0.000878), 100: 2574 (0.001064), 1000: 253770 (0.006196), 10000: 24921357 (0.171522), 100000: 2493902983 (16.9245), 1000000: 249836674360 (1696.16)
            // Selection.   10: 45 (0.000986), 100: 4950 (0.000995), 1000: 499500 (0.006226), 10000: 49995000 (0.095727), 100000: 4999950000 (8.98968), 1000000: 499999500000 (898.247)


    // PHP:
        // With iteration calculation:
            // Bubbles.     10: 45 (0.000023), 100: 4950 (0.000657), 1000: 499499 (0.059985), 10000: 49995000 (6.070219), 100000: 4999949994 (627.978346)
            // Inserts.     10: 21 (0.000006), 100: 2174 (0.000276), 1000: 245271 (0.027567), 10000: 24767003 (2.739803), 100000: 2501300562 (278.207454)
            // Selection.   10: 45 (0.000020), 100: 4950 (0.000253), 1000: 499500 (0.021427), 10000: 49995000 (2.084112), 100000: 4999950000 (206.039659)
        // Without iteration calculation:
            // Bubbles.     10: 45 (0.000021), 100: 4950 (0.000511), 1000: 499499 (0.049860), 10000: 49995000 (5.009871), 100000: 4999949994 (500.853912)
            // Inserts.     10: 21 (0.000020), 100: 2174 (0.000232), 1000: 245271 (0.022502), 10000: 24767003 (2.247104), 100000: 2501300562 (225.239058)
            // Selection.   10: 45 (0.000019), 100: 4950 (0.000143), 1000: 499500 (0.010860), 10000: 49995000 (1.008008), 100000: 4999950000 (100.108101)

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

void insertionSort(int arr[], const int size)
{
    using namespace std;
    int val, prevIndex, prevVal;

    for (int j = 1; j < size; j++) {
        val = arr[j];
    	for (int i = j; i > 0; i--) {
    	    prevIndex = i - 1;
    	    prevVal = arr[prevIndex];
    	    if (val >= prevVal) {
    	        break;
    	    }
    	    arr[prevIndex] = arr[i];
    	    arr[i] = prevVal;
    	}
    }
}

void selectionSort(int arr[], const int size)
{
    using namespace std;
    int val, minValPos, minVal;
    int maxIndex = size - 1;

    for (int j = 0; j < maxIndex; j++) {
        minValPos = j;
        minVal = arr[minValPos];
        for (int i = j + 1; i < size; i++) {
            if (arr[i] < minVal) {
                minValPos = i;
                minVal = arr[i];
            }
        }
        if (minValPos != j) {
            arr[minValPos] = arr[j];
            arr[j] = minVal;
        }
    }
}

// <-- END Sorting algorithms -->