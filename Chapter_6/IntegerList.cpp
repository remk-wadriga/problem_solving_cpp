#include "./ListNode.cpp"

class IntegerList : public AbstractList
{
public:
    IntegerList() : AbstractList() {
        AbstractList();
    };
    IntegerList(int base)
    {
        ListNode* firstItem = new ListNode(base % 10);
        addFirstItem(firstItem);
        int pervVal = base / 10;
        while (pervVal > 0) {
            ListNode* prevItem = new ListNode(pervVal % 10, firstItem);
            addFirstItem(prevItem);
            firstItem = prevItem;
            pervVal /= 10;
        }
    }

    void add(int num)
    {
        appendItem(new ListNode(num));
    }

    void print(std::string sep = "")
    {
        printItems(sep);
        std::cout << "\n";
    }
};