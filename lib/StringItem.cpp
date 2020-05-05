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