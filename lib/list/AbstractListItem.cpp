
class AbstractListItem
{
public:
    std::string virtual toString() = 0;

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