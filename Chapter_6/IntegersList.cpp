#include <iostream>
#include "./IntegerItem.cpp"

class IntegersList : public AbstractList
{
public:
    IntegersList(int base)
    {
        IntegerItem* firstItem = new IntegerItem(base % 10);
        addFirst(firstItem);
        int pervVal = base / 10;
        while (pervVal > 0) {
            IntegerItem* prevItem = new IntegerItem(pervVal % 10, firstItem);
            addFirst(prevItem);
            firstItem = prevItem;
            pervVal /= 10;
        }
    }

    void add(int num)
    {
        IntegerItem* newItem = new IntegerItem(num);
        addFirst(newItem);
    }

    void print(std::string sep = "")
    {
        printItems(sep);
        cout << "\n";
    }
};