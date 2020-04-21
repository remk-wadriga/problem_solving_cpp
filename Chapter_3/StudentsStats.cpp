#include <iostream>
#include <stdio.h>

int compareStudents(const void *voidA, const void *voidB)
{
    Student* studentA = (Student*)(voidA);
    Student* studentB = (Student*)(voidB);
    return studentA->grade - studentB->grade;
}

void printStudents(Student* students, const int size)
{
    using namespace std;
    for (int i = 0; i < size; i++) {
        cout << students[i].toString(", ") << "\n";
    }
}

void sortStudentsByRate(Student* students, const int size)
{
    qsort(students, size, sizeof(Student), compareStudents);
}

int getStudentQuartile(Student* students, const int size, const int minRate)
{
    using namespace std;

    // Sort students by rate
    sortStudentsByRate(students, size);
    printStudents(students, size);

    int minRateIndex = size * minRate / 100;
    if (minRateIndex >= size - 1) {
        minRateIndex = size - 1;
    }

    return students[minRateIndex].grade + 1;
}