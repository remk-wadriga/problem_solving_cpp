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

    const int ARRAY_SIZE = 12;
    int arr[ARRAY_SIZE] = {4, 7, 3, 9, 9, 7, 3, 9, 9, 3, 3, 10};

    srand(time(0));

    printArr(arr, ARRAY_SIZE);
    cout << "\n";

    int mode = calculateMode(arr, ARRAY_SIZE);

    cout << "Mode: " << mode << "\n";

    cout << "Runtime: " << clock() / 1000000.0 << "\n";

    return 0;
}