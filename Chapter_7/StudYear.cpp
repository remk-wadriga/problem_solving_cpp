
class StudentYear: public DecorableInterface
{
public:
    StudentYear(int year): DecorableInterface()
    {
        DecorableInterface();
        setYear(year);
    }

    std::string toString()
    {
        std::string myString = createString(this);
        if (getNext() != NULL) {
            myString += ", " + getNext()->toString();
        }
        return myString;
    }

    void setYear(int newYear) {
        _year = newYear;
    }
    int getYear() {
        return _year;
    }

    void setTitle(std::string newTitle) {
        if (getNext() != NULL) {
            getNext()->setTitle(newTitle);
        }
    }
    std::string getTitle() {
        return getNext() != NULL ? getNext()->getTitle() : "";
    }

    void setAudit(bool newAudit) {
        if (getNext() != NULL) {
            getNext()->setAudit(newAudit);
        }
    }
    bool getAudit() {
        return getNext() != NULL ? getNext()->getAudit() : false;
    }

    void setID(int newID) {
        if (getNext() != NULL) {
            getNext()->setID(newID);
        }
    }
    int getID() {
        return getNext() != NULL ? getNext()->getID() : -1;
    }

    void setGrade(int newGrade) {
        if (getNext() != NULL) {
            getNext()->setGrade(newGrade);
        }
    }
    int getGrade() {
        return getNext() != NULL ? getNext()->getGrade() : -1;
    }

    void setName(std::string newName) {
        if (getNext() != NULL) {
            getNext()->setName(newName);
        }
    }
    std::string getName() {
        return getNext() != NULL ? getNext()->getName() : "";
    }
private:
    int _year;

    friend std::string createString(const StudentYear* stud)
    {
        return "Year: " + std::to_string(stud->_year);
    }
};