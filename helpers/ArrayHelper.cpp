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

int* createHistogram(int arr[], const int maxVal, const int size)
{
    int *histogram = createArray(maxVal, 0);

    for (int i = 0; i < size; i++) {
    	histogram[arr[i] - 1]++;
    }

    return histogram;
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
    cout << "]\n";
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

int maxElement(int arr[], const int size)
{
    int maxElem = 0;
    for (int i = 0; i < size; i++) {
    	if (arr[i] > maxElem || maxElem == 0) {
    	    maxElem = arr[i];
    	}
    }
    return maxElem;
}

// <-- Sorting algorithms -->

// Selection results:
    // C++:
        // With iteration calculation:
            // Bubbles.     10: 45 (0.000823), 100: 4914 (0.000841), 1000: 497609 (0.003192), 10000: 49994880 (0.297736), 100000: 4999876847 (33.7419), 1000000: 499999477209 (3426.62)
            // Gnome.       10: 34 (0.000885), 100: 2574 (0.00092),  1000: 253770 (0.002708), 10000: 24921357 (0.179719), 100000: 2493902983 (17.9426), 1000000: 249836674360 (1805.42)
            // Inserts.     10: 34 (0.000821), 100: 2574 (0.000833), 1000: 253770 (0.002617), 10000: 24921357 (0.173482), 100000: 2493902983 (17.3207), 1000000: 249836674360 (1747.01)
            // Selection.   10: 45 (0.000828), 100: 4950 (0.000838), 1000: 499500 (0.001691), 10000: 49995000 (0.082824), 100000: 4999950000 (8.21922), 1000000: 499999500000 (857.421)
            // Quick.       10: 23 (0.000839), 100: 541 (0.000854),  1000: 8700 (0.001004),   10000: 120501 (0.002622),   100000: 1536461 (0.022524),   1000000: 18673427 (0.255684), 10000000: 220102481 (3.04198), 100000000: 2532928316 (34.7822)
            // Quick stable.10: 30 (0.000838), 100: 679 (0.000784),  1000: 11913 (0.000995),  10000: 148012 (0.003295),   100000: 2018097 (0.030314),   1000000: 24302576 (0.334937), 10000000: 290670342 (3.75129), 100000000: 3461682954 (43.3684)
        // Without iteration calculation:
            // Bubbles.     10: (0.000808), 100: (0.001138), 1000: (0.014371), 10000: (0.306641), 100000: (34.1137), 1000000: (3465.76)
            // Gnome.       10: (0.000763), 100: (0.000812), 1000: (0.002751), 10000: (0.179518), 100000: (18.0026), 1000000: (1797.96)
            // Inserts.     10: (0.000878), 100: (0.001064), 1000: (0.006196), 10000: (0.171522), 100000: (16.9245), 1000000: (1696.16)
            // Selection.   10: (0.000986), 100: (0.000995), 1000: (0.006226), 10000: (0.095727), 100000: (8.98968), 1000000: (898.247)
            // Quick.       10: (0.000803), 100: (0.000772), 1000: (0.001013), 10000: (0.002564), 100000: (0.022071),1000000: (0.251118), 10000000: (2.91902), 100000000: (33.1244)
            // Quick stable.10: (0.000805), 100: (0.000816), 1000: (0.000937), 10000: (0.003257), 100000: (0.0295),  1000000: (0.329109), 10000000: (3.74302), 100000000: (42.5793)
    // PHP:
        // With iteration calculation:
            // Bubbles.     10: 45 (0.000023), 100: 4950 (0.000657), 1000: 499499 (0.059985), 10000: 49995000 (6.070219), 100000: 4999949994 (627.978346)
            // Gnome.       10: 28 (0.000849), 100: 2271 (0.002028), 1000: 246265 (0.033998), 10000: 24776991 (3.378260), 100000: 2501400549 (340.816419)
            // Inserts.     10: 21 (0.000006), 100: 2174 (0.000276), 1000: 245271 (0.027567), 10000: 24767003 (2.739803), 100000: 2501300562 (278.207454)
            // Selection.   10: 45 (0.000020), 100: 4950 (0.000253), 1000: 499500 (0.021427), 10000: 49995000 (2.084112), 100000: 4999950000 (206.039659)
            // Quick.       10: 26 (0.000018), 100: 613 (0.000049),  1000: 9666 (0.000504),   10000: 137765 (0.006867),   100000: 1696108 (0.086057), 1000000: 21054562 (1.010998), 10000000: 246602701 (11.808598)
            // Quick stable.10: 32 (0.000022), 100: 624 (0.000116),  1000: 10144 (0.000725),  10000: 152743 (0.009091),   100000: 1964580 (0.119681), 1000000: 23936123 (1.473444), 10000000: 288887953 (18.617993)
        // Without iteration calculation:
            // Bubbles.     10: (0.000021), 100: (0.000511), 1000: (0.049860), 10000: (5.009871), 100000: (500.853912)
            // Gnome.       10: (0.000020), 100: (0.000324), 1000: (0.032683), 10000: (3.324250), 100000: (330.305371)
            // Inserts.     10: (0.000020), 100: (0.000232), 1000: (0.022502), 10000: (2.247104), 100000: (225.239058)
            // Selection.   10: (0.000019), 100: (0.000143), 1000: (0.010860), 10000: (1.008008), 100000: (100.108101)
            // Quick.       10: (0.000018), 100: (0.000049), 1000: (0.000424), 10000: (0.005710), 100000: (0.070662), 1000000: (0.835028), 10000000: (9.737353)
            // Quick stable.10: (0.000022), 100: (0.000071), 1000: (0.000612), 10000: (0.007830), 100000: (0.097379), 1000000: (1.257766), 10000000: (15.793102)

int compareFunction(const void *voidA, const void *voidB)
{
    int *intA = (int *)(voidA);
    int *intB = (int *)(voidB);
    return *intA - *intB;
}

void quickSort1(int arr[], const int size)
{
    std::qsort(arr, size, sizeof(int), compareFunction);
}

void quickSort(int arr[], const int size)
{
    //using namespace std;

    // Exit condition
    if (size <= 1) {
        return;
    }

    int baseVal = arr[size / 2];
    int smallerSize = 0, equalSize = 0, biggerSize = 0;

    int *smaller = new int[size - 1];
    int *equal = new int[size];
    int *bigger = new int[size - 1];

    for (int i = 0; i < size; i++) {
    	if (arr[i] < baseVal) {
            smaller[smallerSize++] = arr[i];
    	} else if (arr[i] > baseVal) {
            bigger[biggerSize++] = arr[i];
    	} else {
    	    equal[equalSize++] = arr[i];
    	}
    }

    quickSort(smaller, smallerSize);
    quickSort(bigger, biggerSize);

    for (int i = 0; i < smallerSize; i++) {
    	arr[i] = smaller[i];
    }
    for (int i = 0; i < equalSize; i++) {
    	arr[smallerSize + i] = equal[i];
    }
    for (int i = 0; i < biggerSize; i++) {
    	arr[smallerSize + equalSize + i] = bigger[i];
    }

    delete[] smaller;
    delete[] equal;
    delete[] bigger;
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

/**
    Алгоритм смотрит на текущий и предыдущий элементы: если они в правильном порядке,
    он шагает на один элемент вперёд, иначе он меняет их местами и шагает на один элемент назад.
    Граничные условия: если нет предыдущего элемента, он шагает вперёд; если нет следующего, он закончил
*/
void gnomeSort(int arr[], const int size)
{
    using namespace std;
    int val, i = 1, j = 2;

    while (i < size) {
        if (arr[i - 1] > arr[i]) {
            val = arr[i - 1];
            arr[i - 1] = arr[i];
            arr[i] = val;
            if (--i == 0) {
                i = j++;
            }
        } else {
            i = j++;
        }
    }
}

// <-- END Sorting algorithms -->