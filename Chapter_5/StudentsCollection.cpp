#include <iostream>

class StudentsCollection
{
public:
    StudentsCollection()
    {
        _list = NULL;
    }
    ~StudentsCollection()
    {
        deleteList(_list);
    }
    StudentsCollection& operator=(const StudentsCollection& rhs)
    {
        if (this == &rhs) {
            return *this;
        }

        deleteList(_list);
        _list = createListCopy(rhs._list);
        return *this;
    }

    void addRecord(Student student)
    {
        StudentNode* newRecord = createRecord(student);
        newRecord->next = _list;
        _list = newRecord;
    }

    Student findByID(int id)
    {
        StudentNode* record = _list;
        while (record != NULL && record->student.getID() != id) {
            record = record->next;
        }
        if (record == NULL) {
            Student student(-1, -1, "");
            return student;
        }
        return record->student;
    }

    void removeRecord(Student student)
    {
        StudentNode* removedRecord = _list;
        StudentNode* beforeRecord = NULL;

        // Find deleted record and record before it
        while (removedRecord != NULL && removedRecord->student.getID() != student.getID()) {
            beforeRecord = removedRecord;
            removedRecord = removedRecord->next;
        }
        // Record not found by ID? So, there is nothing to do here.
        if (removedRecord == NULL) {
            return;
        }

        // Glue the ends of the chain
        if (beforeRecord != NULL) {
            beforeRecord->next = removedRecord->next;
        } else {
            _list = removedRecord->next;
        }

        // Delete found record;
        delete removedRecord;
    }

    void printStudents()
    {
        using namespace std;

        StudentNode* record = _list;

        while (record != NULL) {
            cout << record->student.toString() << "\n";
            record = record->next;
        }
    }
private:
    struct StudentNode
    {
        Student student;
        StudentNode* next;
    };

    typedef StudentNode* StudentsList;

    StudentsList _list;

    StudentNode* createRecord(Student student)
    {
        StudentNode* record = new StudentNode;
        record->student = student;
        record->next = NULL;
    }

    StudentNode* getLastRecord()
    {
        if (_list == NULL) {
            return NULL;
        }

        StudentNode* lastRecord = _list;
        while (lastRecord->next != NULL) {
            lastRecord = lastRecord->next;
        }
        return lastRecord;
    }

    void deleteList(StudentsList list)
    {
        StudentNode* record = list;
        while (record != NULL) {
            StudentNode* tmpRecord = record;
            record = record->next;
            delete tmpRecord;
        }
    }

    StudentsList createListCopy(StudentsList originList)
    {
        StudentNode* record = originList;
        StudentsList newList = NULL;
        while (record != NULL) {
            StudentNode* newRecord = createRecord(record->student);
            newRecord->next = newList;
            newList = newRecord;
            record = record->next;
        }
        return newList;
    }
};