#include <iostream>
#include "./list/AbstractList.cpp"
#include "./IntegerItem.cpp"

class IntegerList : public AbstractList
{
public:
    IntegerList() : AbstractList() {
        AbstractList();
    };
    IntegerList(int base)
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
        appendItem(new IntegerItem(num));
    }

    void print(std::string sep = "")
    {
        printItems(sep);
        std::cout << "\n";
    }
};