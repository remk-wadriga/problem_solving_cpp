
class AbstractListItem
{
public:
    virtual std::string toString() = 0;

    virtual AbstractListItem* createCopy() = 0;

    void setNext(AbstractListItem* nextItem)
    {
        _next = nextItem;
    }

    AbstractListItem* getNext()
    {
        return _next;
    }

private:
    AbstractListItem* _next;
};