#include <iostream>
#include "./Student.cpp"
#include "./StudentsCollection.cpp"

using namespace std;

void demonstrateStudents()
{
    StudentsCollection collection1;

    Student student1(101, 75, "John");
    Student student2(102, 97, "Joan");
    Student student3(103, 83, "Jack");
    Student student4(104, 63, "Taras");
    Student student5(105, 98, "Olga");
    Student student6(106, 40, "Gavriliuk");
    Student student7(107, 71, "Zelensky");


    collection1.addRecord(student1);
    collection1.addRecord(student2);
    collection1.addRecord(student3);
    collection1.addRecord(student4);
    collection1.addRecord(student5);
    collection1.addRecord(student6);
    collection1.addRecord(student7);

    StudentsCollection collection2 = collection1.recordsWithinRange(75, 80);

    cout << "Collection 1:" << "\n";
    collection1.printStudents();
    cout << "\n";

    cout << "Collection 2:" << "\n";
    collection2.printStudents();
}