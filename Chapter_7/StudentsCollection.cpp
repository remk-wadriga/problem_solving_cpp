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
        int bestGrade = firstStudent->getGrade();

        while ((currentStudent = getNext()) != NULL) {
            if (currentStudent->getGrade() > bestGrade) {
                bestGrade = currentStudent->getGrade();
                firstStudent = currentStudent;
            }
        }

        return firstStudent;
    }

    Student* findFirstStudentByMinID()
    {
        Student* currentStudent;
        Student* firstStudent = getNext();
        int minID = firstStudent->getID();

        while ((currentStudent = getNext()) != NULL) {
            if (currentStudent->getID() < minID) {
                minID = currentStudent->getID();
                firstStudent = currentStudent;
            }
        }

        return firstStudent;
    }

    Student* findFirstStudentByFirstName()
    {
        using namespace std;

        Student* firstStudent = getNext();
        Student* currentStudent;
        StringList firstName(firstStudent->getName());

        while ((currentStudent = getNext()) != NULL) {
            StringList currentName(currentStudent->getName());
            //cout << firstName << " > " << currentName << " " << (firstName > currentName) << "\n";
            if (firstName > currentName) {
                firstName = currentName;
                firstStudent = currentStudent;
            }
        }

        return firstStudent;
    }
};