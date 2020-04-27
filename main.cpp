#include <iostream>
#include <ctime>
#include "./structures/NumInList.cpp"
#include "./helpers/IntegerHelper.cpp"
#include "./helpers/StringHelper.cpp"
#include "./helpers/ArrayHelper.cpp"
#include "./helpers/StatisticsHelper.cpp"

int main()
{
    using namespace std;

    const int ARRAY_SIZE = 10;

    NumList number1 = intToList(22);
    NumList number2 = intToList(33);
    NumList sum = numListsSumOfNumbers(number1, number2);

    cout << number1->toInt() << " + " << number2->toInt() << " = " << sum->toInt() << "\n";

    //int* arr = generateArr(ARRAY_SIZE, 0, 10);
    //cout << arr[0] << ", " << arr[1] << ", " << arr[2] << ", ..., " << arr[ARRAY_SIZE - 3] << ", " << arr[ARRAY_SIZE - 2] << ", " << arr[ARRAY_SIZE - 1] << "\n";
    cout << "Runtime: " << clock() / 1000000.0 << "\n";

    return 0;
}