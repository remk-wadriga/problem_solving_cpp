#include <iostream>
#include <map>
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

    void addExtraField(std::string name, std::string value)
    {
        _extraString[name] = value;
        _extraFields[name] = FIELD_STRING;
    }
    void addExtraField(std::string name, int value)
    {
        _extraInt[name] = value;
        _extraFields[name] = FIELD_INT;
    }
    void addExtraField(std::string name, bool value)
    {
        _extraBool[name] = value;
        _extraFields[name] = FIELD_BOOL;
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
    enum ExtraFields {FIELD_STRING, FIELD_INT, FIELD_BOOL};
    int _id;
    int _grade;
    std::string _name;
    std::map<std::string, ExtraFields> _extraFields;
    std::map<std::string, std::string> _extraString;
    std::map<std::string, int> _extraInt;
    std::map<std::string, bool> _extraBool;

    friend std::string createString(const Student* stud)
    {
        std::string myString = "ID: " + std::to_string(stud->_id) + ", Name: " + stud->_name + ", Grade: " + std::to_string(stud->_grade);

        DecorableInterface* next = ((DecorableInterface*)stud)->getNext();
        if (next != NULL) {
            myString += ", " + next->toString();
        }

        std::map<std::string, std::string> extraString = stud->_extraString;
        std::map<std::string, int> extraInt = stud->_extraInt;
        std::map<std::string, bool> extraBool = stud->_extraBool;
        std::map<std::string, ExtraFields> extraFields = stud->_extraFields;
        std::map<std::string, ExtraFields>::iterator iter;
        for (iter = extraFields.begin(); iter != extraFields.end(); iter++) {
            myString += ", " + iter->first + ": ";
            switch (iter->second) {
                case FIELD_STRING:
                    myString += extraString[iter->first];
                    break;
                case FIELD_INT:
                    myString += std::to_string(extraInt[iter->first]);
                    break;
                case FIELD_BOOL:
                    myString += extraBool[iter->first] == true ? "TRUE" : "FALSE";
                    break;
            }
        }

        return myString;
    }
};