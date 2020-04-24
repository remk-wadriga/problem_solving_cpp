#include <iostream>
#include <ctime>
#include "./helpers/IntegerHelper.cpp"
#include "./helpers/StringHelper.cpp"
#include "./helpers/ArrayHelper.cpp"
#include "./helpers/StatisticsHelper.cpp"
#include "./Chapter_3/Student.cpp"
#include "./Chapter_3/StudentsStats.cpp"
#include "./Chapter_4/StringsFunctions.cpp"
#include "./Chapter_4/StudentCardsFunctions.cpp"

int main()
{
    using namespace std;

    const int ARRAY_SIZE = 10;

    demonstrateStrings4();

    //int* arr = generateArr(ARRAY_SIZE, 0, 10);
    //cout << arr[0] << ", " << arr[1] << ", " << arr[2] << ", ..., " << arr[ARRAY_SIZE - 3] << ", " << arr[ARRAY_SIZE - 2] << ", " << arr[ARRAY_SIZE - 1] << "\n";
    cout << "Runtime: " << clock() / 1000000.0 << "\n";

    return 0;
}