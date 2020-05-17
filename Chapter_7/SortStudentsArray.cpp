#include <iostream>

using namespace std;

Student* createStudentsArray(StudentsCollection* collection)
{
    Student* studentsArray = new Student[collection->getSize()];
    Student* student;
    int i = 0;
    while ((student = collection->getNext()) != NULL) {
        studentsArray[i++] = *student;
    }
    return studentsArray;
}

// <-------- Sort students by grade but left the students with null grades in their places --------->
// 1. Sort students ignore the "null grade" rule
// 2. Include "null grade" rule to the sorting algorithm
//  2.2. Ignore students with null grades on sorting
void sortStudentsArrayByGradeIgnoringNullGrade(Student* students, int size)
{
    // Sort students array
    Student val, prevVal;
    int prevIndex;
    for (int j = 1; j < size; j++) {
        val = students[j];
        if (val.getGrade() == 0) {
            continue;
        }
        for (int i = j; i > 0; i--) {
            prevIndex = i - 1;
            prevVal = students[prevIndex];
            if (val.getGrade() >= prevVal.getGrade()) {
                break;
            }
            students[prevIndex] = students[i];
            students[i] = prevVal;
        }
    }
}

