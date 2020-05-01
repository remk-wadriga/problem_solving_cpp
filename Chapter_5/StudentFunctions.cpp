#include <iostream>
#include "./Student.cpp"
#include "./StudentsCollection.cpp"

using namespace std;

void demonstrateStudents()
{
    StudentsCollection collection1;
    StudentsCollection collection2;

    Student student1(101, 75, "John");
    Student student2(102, 97, "Joan");
    Student student3(103, 83, "Jack");
    Student student4(104, 63, "Taras");
    Student student5(105, 98, "Olga");


    collection1.addRecord(student1);
    collection1.addRecord(student2);
    collection1.addRecord(student3);
    //collection1.addRecord(student4);
    //collection1.addRecord(student5);

    collection2 = collection1;

    cout << "Collection 1:" << "\n";
    collection1.printStudents();
    cout << "\n";
    cout << "Collection 2:" << "\n";
    collection2.printStudents();

    cout << "_____________________________" << "\n";

    collection1.removeRecord(student2);

    cout << "Collection 1:" << "\n";
    collection1.printStudents();
    cout << "\n";
    cout << "Collection 2:" << "\n";
    collection2.printStudents();
}