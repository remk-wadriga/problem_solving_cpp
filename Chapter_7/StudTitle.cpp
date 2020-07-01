
class StudentTitle: public DecorableInterface
{
public:
    StudentTitle(std::string title): DecorableInterface()
    {
        DecorableInterface();
        setTitle(title);
    }

    std::string toString()
    {
        std::string myString = createString(this);
        if (getNext() != NULL) {
            myString += ", " + getNext()->toString();
        }
        return myString;
    }

    void setTitle(std::string newTitle) {
        _title = newTitle;
    }
    std::string getTitle() {
        return _title;
    }

    void setYear(int newYear) {
        if (getNext() != NULL) {
            getNext()->setYear(newYear);
        }
    }
    int getYear() {
        return getNext() != NULL ? getNext()->getYear() : -1;
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
    std::string _title;

    friend std::string createString(const StudentTitle* stud)
    {
        return "Title: " + stud->_title;
    }
};