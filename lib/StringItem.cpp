class StringItem : public AbstractListItem
{
public:
    StringItem(char val, AbstractListItem* next = NULL)
    {
        setVal(val);
        setNext(next);
    }

    // Implementing Interface AbstractListItem
    std::string toString()
    {
        std::string val = "";
        val.push_back(getVal());
        return val;
    }

    AbstractListItem* createCopy()
    {
        return new StringItem(getVal());
    }

    bool isGraterOrEqualOf(const AbstractListItem* rhs) override
    {
        return getVal() >= ((StringItem*)rhs)->getVal();
    }

    bool isGraterOf(const AbstractListItem* rhs) override
    {
        //std::cout << getVal() << " > " << ((StringItem*)rhs)->getVal() << " " << (getVal() > ((StringItem*)rhs)->getVal()) << "\n";
        return getVal() > ((StringItem*)rhs)->getVal();
    }
    // END Implementing Interface AbstractListItem

    // Getters and setters
    void setVal(char val)
    {
        _val = val;
    }
    char getVal()
    {
        return _val;
    }
    // END Getters and setters

private:
    char _val;
};