class IntegerItem : public AbstractListItem
{
public:
    IntegerItem(int val, AbstractListItem* next = NULL)
    {
        setVal(val);
        setNext(next);
    }

    // Implementing Interface AbstractListItem
    std::string toString()
    {
        return std::to_string(_val);
    }

    AbstractListItem* createCopy()
    {
        return new IntegerItem(getVal());
    }
    // END Implementing Interface AbstractListItem

    // Getters and setters
    void setVal(int val)
    {
        _val = val;
    }
    int getVal()
    {
        return _val;
    }
    // END Getters and setters
private:
    int _val;
};