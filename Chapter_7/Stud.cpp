#include <iostream>
#include "./DecorableInterface.cpp"
#include "./StudTitle.cpp"
#include "./StudYear.cpp"
#include "./StudAudit.cpp"

class Student: public DecorableInterface
{
public:
    Student(): DecorableInterface()
    {
        DecorableInterface();
        setID(-1);
        setGrade(0);
        setName("");
    }
    Student(int ID, int grade, std::string name)
    {
        setID(ID);
        setGrade(grade);
        setName(name);
    }
    friend std::ostream& operator<<(std::ostream &os, const Student &dt)
    {
        os << createString(&dt);
        return os;
    }

    std::string toString()
    {
        return createString(this);
    }

    // Getters and setters
    void setID(int newID)
    {
        _id = newID;
    }
    int getID()
    {
        return _id;
    }

    void setGrade(int newGrade)
    {
        _grade = newGrade;
    }
    int getGrade()
    {
        return _grade;
    }

    void setName(std::string newName)
    {
        _name = newName;
    }
    std::string getName()
    {
        return _name;
    }
    // END Getters and setters
private:
    int _id;
    int _grade;
    std::string _name;

    friend std::string createString(const Student* stud)
    {
        std::string myString = "ID: " + std::to_string(stud->_id) + ", Name: " + stud->_name + ", Grade: " + std::to_string(stud->_grade);

        DecorableInterface* next = ((DecorableInterface*)stud)->getNext();
        if (next != NULL) {
            myString += ", " + next->toString();
        }

        return myString;
    }
};