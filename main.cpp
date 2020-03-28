#include <iostream>
#include <ctime>
#include "./helpers/IntegerHelper.cpp"
#include "./helpers/StringHelper.cpp"
#include "./helpers/ArrayHelper.cpp"
#include "./Chapter_3/Statistics.cpp"

int main()
{
    using namespace std;

    /*int size;
    cout << "Set array size:\n> ";
    cin >> size;
    const int ARRAY_SIZE = size;
    int* arr = generateArr(ARRAY_SIZE, -size, size);*/

    //const int ARRAY_SIZE = 12;
    //int arr[ARRAY_SIZE] = {4, 7, 3, 9, 9, 7, 3, 9, 9, 3, 3, 10};

    // Gnome.   10: (0.000763), 100: (0.000812), 1000: (0.002751), 10000: (0.179518), 100000: (18.0026), 1000000: (1797.96)

    const int ARRAY_SIZE = 1000000;
    int* arr = generateArr(ARRAY_SIZE, -ARRAY_SIZE, ARRAY_SIZE);

    //printArr(arr, ARRAY_SIZE);
    cout << "\n";

    gnomeSort(arr, ARRAY_SIZE);

    //printArr(arr, ARRAY_SIZE);
    cout << "\n";

    srand(time(0));

    /*printArr(arr, ARRAY_SIZE);
    cout << "\n";

    int mode = calculateMode(arr, ARRAY_SIZE);*/



    //cout << "Mode: " << mode << "\n";

    cout << "Runtime: " << clock() / 1000000.0 << "\n";

    return 0;
}