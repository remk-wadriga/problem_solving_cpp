#include <iostream>
#include <ctime>
#include "./helpers/IntegerHelper.cpp"
#include "./helpers/StringHelper.cpp"
#include "./helpers/ArrayHelper.cpp"
#include "./helpers/StatisticsHelper.cpp"
#include "./Chapter_3/Student.cpp"

int main()
{
    using namespace std;

    const int ARRAY_SIZE = 10000000;
    int *arr = generateArr(ARRAY_SIZE, -ARRAY_SIZE, ARRAY_SIZE);

    //printArr(arr, ARRAY_SIZE); cout << "\n";

    srand(time(0));

    quickSort(arr, ARRAY_SIZE);

    cout << arr[0] << ", " << arr[1] << " ... " << arr[ARRAY_SIZE - 2] << ", " << arr[ARRAY_SIZE - 1] << "\n";

    //printArr(arr, ARRAY_SIZE);

    // Quick.       10: 30 (0.000838), 100: 679 (0.000784), 1000: 11913 (0.000995), 10000: 148012 (0.003295), 100000: 2018097 (0.030314), 1000000: 24302576 (0.334937), 10000000: 290670342 (3.75129), 100000000: 3461682954 (43.3684)
    // Quick.       10: (0.000805), 100: (0.000816), 1000: (0.000937), 10000: (0.003257), 100000: (0.0295), 1000000: (0.329109), 10000000: (3.74302), 100000000: (42.5793)

    // Quick.       10: 00 (), 100: 00 (), 1000: 00 (), 10000: 00 (), 100000: 00 (), 1000000: 00 (), 10000000:  (), 100000000:  ()
    // Quick.       10: (), 100: (), 1000: (), 10000: (), 100000: (), 1000000: (), 10000000: (), 100000000: ()

    /*Student students[ARRAY_SIZE] = {
        {87, 10001, "Fred"},
        {28, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {75, 10011, "Leslie"},
        {70, 10008, "Candy"},
        {81, 10009, "Aretha"},
        {68, 10010, "Veronica"},
    };

    Student bestStudent = students[0];
    for (int i = 1; i < ARRAY_SIZE; i++) {
    	if (students[i].grade > bestStudent.grade) {
    	    bestStudent = students[i];
    	}
    }

    cout << "Best student:\n" << bestStudent.toString() << "\n";*/



    cout << "Runtime: " << clock() / 1000000.0 << "\n";

    return 0;
}