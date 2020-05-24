#include <iostream>
#include <list>
#include "./Stud.cpp"

using namespace std;

void addStudentCardRecordToStart(list<Student> &students, int num, int grade, string name)
{
    students.push_front(Student(num, grade, name));
}

void addStudentCardRecordToEnd(list<Student> &students, int num, int grade, string name)
{
    students.push_back(Student(num, grade, name));
}

double averageStudentCardGrade(list<Student> students)
{
    double sum = 0.0, count = 0.0;
    for (list<Student>::iterator it = students.begin(); it != students.end(); it++) {
        count++;
        sum += ((Student)*it).getGrade();
    }
    return count > 0 ? sum / count : 0.0;
}

void demonstrateStudents()
{
    Student student1(101, 75, "John");
    Student student2(102, 97, "Joan");
    Student student3(103, -1, "Jack");
    Student student4(104, 63, "Taras");
    Student student5(105, 98, "Olga");
    Student student6(106, 40, "Gavriliuk");
    Student student7(107, 71, "Zelensky");
    Student student8(108, -1, "Adam");

    Student students[] = {student1, student2, student3, student4, student5, student6, student7, student8};
    list<Student> list1 (students, students + 8);

    addStudentCardRecordToEnd(list1, 109, 67, "Vasiliy");

    for (list<Student>::iterator it = list1.begin(); it != list1.end(); it++) {
        cout << *it << "\n";
    }

    cout << "Avarage grade: " << averageStudentCardGrade(list1) << "\n";

    cout << "\n";
}