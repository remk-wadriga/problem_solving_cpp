#include <iostream>
#include "./SearchStudentPolicy.cpp"
#include "./SortStudentsArray.cpp"

using namespace std;

void demonstrateStudents()
{
    StudentsCollection collection1;

    Student* student1 = new Student(101, 75, "John");
    Student* student2 = new Student(102, 97, "Joan");
    Student* student3 = new Student(103, -1, "Jack");
    Student* student4 = new Student(104, 63, "Taras");
    Student* student5 = new Student(105, 98, "Olga");
    Student* student6 = new Student(106, 40, "Gavriliuk");
    Student* student7 = new Student(107, 71, "Zelensky");
    Student* student8 = new Student(108, -1, "Adam");

    collection1.add(student1);
    collection1.add(student2);
    collection1.add(student3);
    collection1.add(student4);
    collection1.add(student5);
    collection1.add(student6);
    collection1.add(student7);
    collection1.add(student8);

    /*SearchStudentPolicy studentFinder;
    studentFinder.setHead((Student*)collection1.getHead());
    studentFinder.setPolicy(studentFinder.BEST_GRADE);
    studentFinder.setPolicy(studentFinder.MIN_ID);
    studentFinder.setPolicy(studentFinder.FIRST_NAME);*/

    cout << "Collection 1:" << "\n";
    //collection1.print();
    //cout << "---------------------------------------------------" << "\n";

    /*cout << "First student:\n";
    Student* firstStudent = collection1.findFirstStudent(collection1.FIRST_NAME);
    cout << firstStudent->toString() << "\n";*/

    /*Student firstStudent = studentFinder.getFirstStudent();
    cout << firstStudent.toString() << "\n";*/

    Student* studentsArray = createStudentsArray(&collection1);
    sortStudentsArrayByGradeIgnoringNullGradeInserts(studentsArray, collection1.getSize());
    for (int i = 0; i < 8; i++) {
        cout << studentsArray[i].toString() << "\n";
    }
    cout << "\n";


    //cout << "---------------------------------------------------" << "\n";
    //collection1.print();

    cout << "\n";
}