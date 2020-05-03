#include "./InterfaceListItem.cpp"

class AbstractList
{
public:
    AbstractList()
    {
        _headItem = NULL;
    }
    InterfaceListItem* getHead()
    {
        return _headItem;
    }

    void addFirst(InterfaceListItem* newItem)
    {
        newItem->setNext(_headItem);
        _headItem = newItem;
    }

    void printItems(std::string sep = "\n")
    {
        using namespace std;
        InterfaceListItem* item = _headItem;
        while (item != NULL) {
            cout << item->toString() << sep;
            item = item->getNext();
        }
    }
protected:
    InterfaceListItem* _headItem;
};