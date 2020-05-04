#include "./AbstractListItem.cpp"

class AbstractList
{
public:
    // Constructor
    AbstractList()
    {
        _headItem = NULL;
        _currentItem = NULL;
    }
    // Destructor
    ~AbstractList()
    {
        deleteList(_headItem);
        _headItem = NULL;
    }

    // Reload operator "=" to correct assign an object to variable with with link to another object this type
    AbstractList& operator=(const AbstractList& rhs)
    {
        if (this == &rhs) {
            return *this;
        }

        deleteList(_headItem);
        _headItem = createItemsCopy(rhs._headItem);
        return *this;
    }


    AbstractListItem* getHead()
    {
        return _headItem;
    }

    // Find item by index
    AbstractListItem* getItem(const int index)
    {
        AbstractListItem* item = getHead();
        int i = 0;
        while (i++ < index && item != NULL) {
            item = item->getNext();
        }
        return item;
    }

    // Find item index
    int indexOfItem(AbstractListItem* item)
    {
        int index = 0, result = -1;
        AbstractListItem* currentItem;
        while ((currentItem = getNextItem()) != NULL) {
            if (currentItem == item) {
                result = index;
                break;
            }
            index++;
        }
        return result;
    }

    // Get last item of list
    AbstractListItem* getLastItem()
    {
        AbstractListItem* item;
        while (getNextItem() != NULL) {
            item = getCurrentItem();
        }
        return item;
    }

    // Add item to the head of list
    void addFirstItem(AbstractListItem* newItem)
    {
        newItem->setNext(_headItem);
        _headItem = newItem;
    }

    // Add item to the middle of list
    void addAfterItem(AbstractListItem* newItem, int index)
    {
        int i = 0;
        AbstractListItem* beforeItem = getHead();
        if (beforeItem == NULL || index == -1) {
            addFirstItem(newItem);
            return;
        }
        while (i < index && beforeItem->getNext() != NULL) {
            i++;
            beforeItem = beforeItem->getNext();
        }
        newItem->setNext(beforeItem->getNext());
        beforeItem->setNext(newItem);
    }

    // Add item to the end of list
    void addLastItem(AbstractListItem* newItem)
    {
        AbstractListItem* lastItem = getLastItem();
        if (lastItem == NULL) {
            addFirstItem(newItem);
        } else {
            lastItem->setNext(newItem);
        }
    }

    // Add list to the head
    void addFirstList(const AbstractList* list)
    {
        if (list->_headItem == NULL) {
            return;
        }
        AbstractListItem* firstItem = createItemsCopy(list->_headItem);
        AbstractListItem* lastItem = firstItem;
        while (lastItem->getNext() != NULL) {
            lastItem = lastItem->getNext();
        }
        lastItem->setNext(_headItem);
        _headItem = firstItem;
    }

    // Add list to the middle
    void addAfterList(const AbstractList* list, int index)
    {
        if (list->_headItem == NULL) {
            return;
        }
        AbstractListItem* beforeItem = getHead();
        if (beforeItem == NULL || index == -1) {
            addFirstList(list);
            return;
        }

        AbstractListItem* firstItem = createItemsCopy(list->_headItem);
        AbstractListItem* lastItem = firstItem;
        while (lastItem->getNext() != NULL) {
            lastItem = lastItem->getNext();
        }
        int i = 0;
        while (i < index && beforeItem->getNext() != NULL) {
            i++;
            beforeItem = beforeItem->getNext();
        }
        lastItem->setNext(beforeItem->getNext());
        beforeItem->setNext(firstItem);
    }

    // Add list to the end
    void addLastList(const AbstractList* list)
    {
        if (list->_headItem == NULL) {
            return;
        }
        AbstractListItem* firstItem = createItemsCopy(list->_headItem);
        AbstractListItem* lastItem = getLastItem();
        if (lastItem != NULL) {
            lastItem->setNext(firstItem);
        } else {
            _headItem = firstItem;
        }
    }

    // Get items count
    int getSize()
    {
        int count = 0;
        while (getNextItem() != NULL) {
            count++;
        }
        return count;
    }

    // Get current iterations item
    AbstractListItem* getCurrentItem()
    {
        return _currentItem != NULL ? _currentItem : getHead();
    }

    // Get next iterations item
    AbstractListItem* getNextItem()
    {
        return _currentItem = _currentItem != NULL ? _currentItem->getNext() : getHead();
    }

    void printItems(std::string sep = "\n")
    {
        AbstractListItem* item;
        while ((item = getNextItem()) != NULL) {
            std::cout << item->toString() << sep;
        }
    }
private:
    AbstractListItem* _headItem;
    AbstractListItem* _currentItem;

    AbstractList* createCopy()
    {
        AbstractList* newList = new AbstractList();
        newList->_headItem = createItemsCopy(_headItem);
        return newList;
    }

    AbstractListItem* createItemsCopy(AbstractListItem* item)
    {
        if (item == NULL) {
            return NULL;
        }
        AbstractListItem* firstItem = item->createCopy();
        AbstractListItem* lastItem = firstItem;
        item = item->getNext();
        while (item != NULL) {
            AbstractListItem* newItem = item->createCopy();
            lastItem->setNext(newItem);
            lastItem = newItem;
            item = item->getNext();
        }
        lastItem->setNext(NULL);
        return firstItem;
    }

    void deleteList(AbstractListItem* item)
    {
        while (item != NULL) {
            AbstractListItem* tmpItem = item;
            item = item->getNext();
            delete tmpItem;
        }
    }
};