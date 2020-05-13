
class AbstractListItem
{
public:
    virtual std::string toString() = 0;

    virtual AbstractListItem* createCopy() = 0;

    bool operator>=(const AbstractListItem& rhs)
    {
        return this->isGraterOrEqualOf(&rhs);
    }

    bool operator>(const AbstractListItem& rhs)
    {
        return this->isGraterOf(&rhs);
    }

    virtual bool isGraterOrEqualOf(const AbstractListItem* rhs)
    {
        return false;
    }

    virtual bool isGraterOf(const AbstractListItem* rhs)
    {
        return false;
    }

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