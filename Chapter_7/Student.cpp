
class Student: public AbstractListItem
{
public:
    Student()
    {
        setID(-1);
        setGrade(0);
        setName("");
        setNext(NULL);
    }
    Student(int ID, int grade, std::string name, AbstractListItem* next = NULL)
    {
        setID(ID);
        setGrade(grade);
        setName(name);
        setNext(next);
    }

    // Implementing Interface AbstractListItem
    std::string toString()
    {
        return "ID: " + std::to_string(getID()) + ", Name: " + getName() + ", Grade: " + std::to_string(getGrade());
    }

    AbstractListItem* createCopy()
    {
        return new Student(getID(), getGrade(), getName());
    }
    // END Implementing Interface AbstractListItem

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
        if (isValidGrade(newGrade)) {
            _grade = newGrade;
        }
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


    // Public methods
    std::string letterGrade()
    {
        int NUMBER_CATEGORIES = 11;
        std::string GRADE_LETTER[NUMBER_CATEGORIES] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
        int LOWEST_GRADE_SCORE[NUMBER_CATEGORIES] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};

        if (!isValidGrade(_grade)) {
            return "ERROR";
        }
        int category = 0;
        while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade) {
            category++;
        }
        return GRADE_LETTER[category - 1];
    }
    // END Public methods

private:
    int _id;
    int _grade;
    std::string _name;

    // Private methods
    bool isValidGrade(int grade)
    {
        return grade >= 0 && grade <= 100;
    }
    // END Private methods
};