#include <iostream>
#include <string.h>
#include "./StudentsCollection.cpp"

using namespace std;

bool higherGrade(Student s1, Student s2)
{
    return s1.getGrade() > s2.getGrade();
}

bool lowerStudentNumber(Student s1, Student s2)
{
    return s1.getID() < s2.getID();
}

bool nameComesFirst(Student s1, Student s2)
{
    //return strcmp(s1.getName().c_str(), s2.getName().c_str()) < 0;
    return s1.getName() < s2.getName();
}

class SearchStudentPolicy
{
public:
    enum searchPolicy {BEST_GRADE, MIN_ID, FIRST_NAME};

    // "firstStudentPolicy" - This is the pointer to function which search the student from list by some algorithm
    typedef bool (* searchStudentPolicy)(Student s1, Student s2);

    SearchStudentPolicy()
    {
        _head = NULL;
        _policy = NULL;
    }

    void setHead(Student* head)
    {
        _head = head;
    }

    void setPolicy(searchPolicy policy)
    {
        switch (policy) {
            case BEST_GRADE:
                _policy = higherGrade;
                break;
            case MIN_ID:
                _policy = lowerStudentNumber;
                break;
            case FIRST_NAME:
                _policy = nameComesFirst;
                break;
        }
    }

    Student getFirstStudent()
    {
        if (_head == NULL || _policy == NULL) {
            return Student(-1, -1, "");
        }

        Student* firstRecord = _head;
        Student* nextRecord = (Student*)(_head->getNext());
        while (nextRecord != NULL) {
            if (_policy(*nextRecord, *firstRecord)) {
                firstRecord = nextRecord;
            }
            nextRecord = (Student*)(nextRecord->getNext());
        }

        return *firstRecord;
    }
private:
    Student* _head;
    searchStudentPolicy _policy;
};