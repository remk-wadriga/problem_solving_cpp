#include <iostream>
#include <ctime>
#include "./helpers/IntegerHelper.cpp"
#include "./helpers/StringHelper.cpp"
#include "./helpers/ArrayHelper.cpp"
#include "./Chapter_3/Statistics.cpp"

int main()
{
    using namespace std;

    const int ARRAY_SIZE = 12;
    int arr[ARRAY_SIZE] = {3, 7, 3, 9, 9, 9, 3, 9, 9, 3, 3, 3};

    srand(time(0));

    int mode = calculateMode(arr, ARRAY_SIZE);

    cout << "Mode: " << mode << "\n";

    cout << "Runtime: " << clock() / 1000000.0 << "\n";

    return 0;
}