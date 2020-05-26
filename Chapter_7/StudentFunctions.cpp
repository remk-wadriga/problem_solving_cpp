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

    Student students[] = {student6, student2, student3, student8, student4, student5, student1, student7, };
    /*list<Student> list1 (students, students + 8);
    addStudentCardRecordToEnd(list1, 109, 67, "Vasiliy");
    for (list<Student>::iterator it = list1.begin(); it != list1.end(); it++) {
        cout << *it << "\n";
    }*/

    /*sortStudentsByID(students, 8);
    for (int i = 0; i < 8; i++) {
    	cout << students[i] << "\n";
    }*/

    int arr[] = {2, 5, 6, 9, 12, 15, 17, 18, 19, 20, 27, 33, 34, 35, 40, 41, 45, 47, 50};
    //           0  1  2  3  4   5   6   7   8   9   10  11  12  13  14  15  16  17  18
    for (int i = 0; i < 19; i++) {
    	cout << arr[i] << " => " << interpolationSearch(arr, 19, arr[i]) << "\n";
    }
    //int arr[] = {2, 5, 6, 9, 12};
    //cout << interpolationSearch(arr, 13, 27) << "\n";

    cout << "\n";
}