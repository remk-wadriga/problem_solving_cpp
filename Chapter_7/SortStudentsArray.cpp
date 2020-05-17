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
//  2.1. Ignore students with null grades on sorting
void sortStudentsArrayByGradeIgnoringNullGradeInserts(Student* students, int size)
{
    // Sort students array
    for (int j = 1; j < size; j++) {
        Student val = students[j];
        if (val.getGrade() == 0) {
            continue;
        }
        for (int i = j; i > 0; i--) {
            int prevIndex = i - 1;
            Student prevVal = students[prevIndex];
            while (prevVal.getGrade() == 0 && prevIndex > 0) {
                prevVal = students[--prevIndex];
            }
            if (val.getGrade() >= prevVal.getGrade()) {
                break;
            }
            students[prevIndex] = val;
            students[i] = prevVal;
        }
    }
}


int compareStudentsFunction(const void* voidA, const void* voidB)
{
    Student* studentA = (Student*)(voidA);
    Student* studentB = (Student*)(voidB);
    return studentA->getGrade() - studentB->getGrade();
}

void sortStudentsArrayByGradeIgnoringNullGradeQuick(Student* students, int size)
{
    // Create students array copy
    Student* studentsTmp = new Student[size];
    for (int i = 0; i < size; i++) {
    	studentsTmp[i] = students[i];
    }
    // Sort tmp array
    qsort(students, size, sizeof(Student), compareStudentsFunction);
    // Copy students from

}

