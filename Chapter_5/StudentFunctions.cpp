#include <iostream>
#include "./Student.cpp"

using namespace std;

void demonstrateStudents()
{
    Student* student = new Student();
    cout << student->toString() << "\n";
    cout << "Letter grade: " << student->letterGrade() << "\n";
}