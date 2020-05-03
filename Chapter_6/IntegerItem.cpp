class IntegerItem : public InterfaceListItem
{
public:
    IntegerItem(int val, InterfaceListItem* next = NULL)
    {
        _val = val;
        _next = NULL;
    }

    // Implementing Interface InterfaceListItem
    void setNext(InterfaceListItem* nextItem)
    {
        _next = nextItem;
    }
    InterfaceListItem* getNext()
    {
        return _next;
    }
    std::string toString()
    {
        return std::to_string(_val);
    }
    // END Implementing Interface InterfaceListItem

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
    InterfaceListItem* _next;
};