#include <iostream>
#include "./IntegerItem.cpp"

class IntegersList : public AbstractList
{
public:
    IntegersList() : AbstractList() {
        AbstractList();
    };
    IntegersList(int base)
    {
        IntegerItem* firstItem = new IntegerItem(base % 10);
        addFirstItem(firstItem);
        int pervVal = base / 10;
        while (pervVal > 0) {
            IntegerItem* prevItem = new IntegerItem(pervVal % 10, firstItem);
            addFirstItem(prevItem);
            firstItem = prevItem;
            pervVal /= 10;
        }
    }

    void add(int num)
    {
        addLastItem(new IntegerItem(num));
    }

    void print(std::string sep = "")
    {
        printItems(sep);
        cout << "\n";
    }
};