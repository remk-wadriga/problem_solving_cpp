
class StudentAudit: public DecorableInterface
{
public:
    StudentAudit(bool audit): DecorableInterface()
    {
        DecorableInterface();
        setAudit(audit);
    }

    std::string toString()
    {
        std::string myString = createString(this);
        if (getNext() != NULL) {
            myString += ", " + getNext()->toString();
        }
        return myString;
    }

    void setAudit(bool newAudit) {
        _audit = newAudit;
    }
    bool getAudit() {
        return _audit;
    }

    void setTitle(std::string newTitle) {
        if (getNext() != NULL) {
            getNext()->setTitle(newTitle);
        }
    }
    std::string getTitle() {
        return getNext() != NULL ? getNext()->getTitle() : "";
    }

    void setYear(int newYear) {
        if (getNext() != NULL) {
            getNext()->setYear(newYear);
        }
    }
    int getYear() {
        return getNext() != NULL ? getNext()->getYear() : -1;
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
    bool _audit;

    friend std::string createString(const StudentAudit* stud)
    {
        std::string audit = stud->_audit == true ? "TRUE" : "FALSE";
        return "Audit: " + (audit);
    }
};