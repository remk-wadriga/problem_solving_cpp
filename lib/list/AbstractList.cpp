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

    // Get items count
    int getSize()
    {
        int count = 0;
        while (getNextItem() != NULL) {
            count++;
        }
        return count;
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
    void insertItem(AbstractListItem* newItem, int index)
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
    void appendItem(AbstractListItem* newItem)
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
    void insertList(const AbstractList* list, int index)
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
    void appendList(const AbstractList* list)
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

    // Remove "length" from "pos" position
    void remove(int pos, int length)
    {
        // 0. First position can not bo less than 0
        if (pos < 0) {
            pos = 0;
        }

        // 1. Get list length and check is start deleting position is correct
        int listLength = getSize();
        if (pos >= listLength - 1 || listLength == 0) {
            return;
        }

        // 2. Set correct length for special cases (length == 0 - delete all after first found, length < 0 - delete all from "pos" to "lastPos" - abs(length))
        if (length == 0) {
            length = listLength;
        } else if (length < 0) {
            length = listLength + length - pos;
        }

        // 3. Find first item before deleted
        AbstractListItem* firstItem = pos > 0 ? getHead() : NULL;
        int i = 0;
        while (i++ < pos - 1 && firstItem != NULL) {
            firstItem = firstItem->getNext();
        }

        // 4. Delete "length" items after founded and find next item after deleted items
        AbstractListItem* deleteItem = firstItem != NULL ? firstItem->getNext() : getHead();
        AbstractListItem* nextItem = NULL;
        i = 0;
        while (i++ < length && deleteItem != NULL) {
            nextItem = deleteItem->getNext();
            delete deleteItem;
            deleteItem = nextItem;
        }

        // 5. Set item founded in step 4 as "next" to the item founded in step 3
        if (firstItem != NULL) {
            firstItem->setNext(nextItem);
        } else {
            _headItem = nextItem;
        }
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

    std::string toString()
    {
        std::string res = "";
        AbstractListItem* item;
        while ((item = getNextItem()) != NULL) {
            res += item->toString();
        }
        return res;
    }

    void printItems(std::string sep = "\n")
    {
        AbstractListItem* item;
        while ((item = getNextItem()) != NULL) {
            std::cout << item->toString() << sep;
        }
    }
protected:
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