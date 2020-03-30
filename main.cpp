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

    const int ARRAY_SIZE = 10;

    Student students[ARRAY_SIZE] = {
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

    cout << "Best student:\n" << bestStudent.toString() << "\n";

    cout << "Runtime: " << clock() / 1000000.0 << "\n";

    return 0;
}