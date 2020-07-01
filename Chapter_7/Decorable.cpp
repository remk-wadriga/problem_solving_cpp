
class Decorable
{
    public:
        virtual void setID(int newID) {}
        virtual int getID() {}

        virtual void setGrade(int newGrade) {}
        virtual int getGrade() {}

        virtual void setName(std::string newName) {}
        virtual std::string getName() {}

        virtual void setTitle(std::string newTitle) {}
        virtual std::string getTitle() {}

        virtual void setYear(int newYear) {}
        virtual int getYear() {}

        virtual void setAudit(bool newAudit) {}
        virtual bool getAudit() {}
};