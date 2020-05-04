#include "./AbstractListItem.cpp"

class AbstractList
{
public:
    AbstractList()
    {
        _headItem = NULL;
    }
    AbstractListItem* getHead()
    {
        return _headItem;
    }

    void addFirst(AbstractListItem* newItem)
    {
        newItem->setNext(_headItem);
        _headItem = newItem;
    }

    void printItems(std::string sep = "\n")
    {
        using namespace std;
        AbstractListItem* item = _headItem;
        while (item != NULL) {
            cout << item->toString() << sep;
            item = item->getNext();
        }
    }
protected:
    AbstractListItem* _headItem;
};