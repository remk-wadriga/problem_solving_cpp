#include <iostream>

class Student
{
public:
    Student()
    {
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
    Student* setID(int newID)
    {
        _id = newID;
        return this;
    }
    int getID()
    {
        return _id;
    }

    Student* setGrade(int newGrade)
    {
        _grade = newGrade;
        return this;
    }
    int getGrade()
    {
        return _grade;
    }

    Student* setName(std::string newName)
    {
        _name = newName;
        return this;
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
        return "ID: " + std::to_string(stud->_id) + ", Name: " + stud->_name + ", Grade: " + std::to_string(stud->_grade);
    }
};