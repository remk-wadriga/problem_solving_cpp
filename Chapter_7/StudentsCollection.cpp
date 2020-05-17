#include <iostream>
#include "./Student.cpp"

class StudentsCollection: public AbstractList
{
public:
    enum firstStudentSearchMode {BEST_GRADE, MIN_ID, FIRST_NAME};

    StudentsCollection() : AbstractList() {
        AbstractList();
    };

    void add(Student* student)
    {
        addFirstItem(student);
    }

    void print(std::string sep = "\n")
    {
        printItems(sep);
        std::cout << "\n";
    }

    Student* getCurrent()
    {
        return (Student*)getCurrentItem();
    }

    Student* getNext()
    {
        return (Student*)getNextItem();
    }

    Student* findFirstStudent(firstStudentSearchMode mode)
    {
        switch (mode) {
            case BEST_GRADE:
                return findFirstStudentByBestGrade();
                break;
            case MIN_ID:
                return findFirstStudentByMinID();
                break;
            case FIRST_NAME:
                return findFirstStudentByFirstName();
                break;
        }
    }

private:
    Student* findFirstStudentByBestGrade()
    {
        Student* currentStudent;
        Student* firstStudent = getNext();
        while ((currentStudent = getNext()) != NULL) {
            if (currentStudent->getGrade() > firstStudent->getGrade()) {
                firstStudent = currentStudent;
            }
        }
        return firstStudent;
    }

    Student* findFirstStudentByMinID()
    {
        Student* currentStudent;
        Student* firstStudent = getNext();
        while ((currentStudent = getNext()) != NULL) {
            if (currentStudent->getID() < firstStudent->getID()) {
                firstStudent = currentStudent;
            }
        }
        return firstStudent;
    }

    Student* findFirstStudentByFirstName()
    {
        Student* firstStudent = getNext();
        Student* currentStudent;
        while ((currentStudent = getNext()) != NULL) {
            if (currentStudent->getName() < firstStudent->getName()) {
                firstStudent = currentStudent;
            }
        }
        return firstStudent;
    }
};