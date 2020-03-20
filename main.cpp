#include <iostream>
#include <ctime>
#include "./helpers/IntegerHelper.cpp"
#include "./helpers/StringHelper.cpp"
#include "./helpers/ArrayHelper.cpp"

int main()
{
    using namespace std;

    int size;
    cout << "Set array size:\n> ";
    cin >> size;
    const int ARRAY_SIZE = size;
    int* arr = generateArr(ARRAY_SIZE, -size, size);

    srand(time(0));
    


    cout << "Runtime: " << clock() / 1000000.0 << "\n";

    return 0;
}