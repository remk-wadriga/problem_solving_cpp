#include <iostream>
#include <list>
#include <map>
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

int compareStudentsFunction(const void* voidA, const void* voidB)
{
    Student* studentA = (Student*)(voidA);
    Student* studentB = (Student*)(voidB);
    return studentA->getID() - studentB->getID();
}

void sortStudentsByID(Student students[], const int count)
{
    qsort(students, count, sizeof(Student), compareStudentsFunction);
}

int getStudentGradeFunction(void* voidStud)
{
    return ((Student*)(voidStud))->getGrade();
}

void demonstrateStudents()
{
    Student student1(101, 32, "John");
    Student student2(102, 45, "Joan");
    Student student3(103, 66, "Jack");
    Student student4(104, 67, "Taras");
    Student student5(105, 73, "Olga");
    Student student6(106, 88, "Gavriliuk");
    Student student7(107, 90, "Zelensky");
    Student student8(108, 95, "Adam");

    /*map<string, Student> students {
        {student1.getName(), student1},
        {student2.getName(), student2},
        {student3.getName(), student2},
        {student4.getName(), student2},
        {student5.getName(), student2},
        {student6.getName(), student2},
        {student7.getName(), student2},
    };
    students[student8.getName()] = student8;*/

    //students.getHash(student7.getName());
    //students.getHash(student1.getName());
    //cout << student8.getName() << " => " << students.getHash(student8.getName(), 32) << "\n";

    //cout << student8.getName() << " => " << students[student8.getName()] << "\n";

    HashMap<string, Student> students;

    students.add(student1.getName(), student1);
    students.add(student2.getName(), student2);
    students.add(student3.getName(), student3);
    students.add(student4.getName(), student4);
    students.add(student5.getName(), student5);
    students.add(student6.getName(), student6);
    students.add(student7.getName(), student7);
    students.add(student8.getName(), student8);

    cout << student7.getName() << " => " << *students.get(student7.getName()) << "\n";

    //cout << student3.getName() << " => " << students.getHash(student3.getName()) << "\n";

    cout << "\n";
}