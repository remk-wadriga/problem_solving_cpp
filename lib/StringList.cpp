#include <iostream>
#include "./list/AbstractList.cpp"
#include "./StringItem.cpp"

class StringList : public AbstractList
{
public:
    StringList() : AbstractList() {
        AbstractList();
    };

    StringList(std::string base)
    {
        int length = base.length();
        for (int i = length - 1; i >= 0; i--) {
            addFirstItem(new StringItem(base[i]));
        }
    }

    void print(std::string sep = "")
    {
        printItems(sep);
        cout << "\n";
    }

    void addFirst(char chr)
    {
        addFirstItem(new StringItem(chr));
    }

    void insert(char chr, int index)
    {
        insertItem(new StringItem(chr), index);
    }
    
    void insert(std::string str, int index)
    {
        StringList* tmpList = new StringList(str);
        insertList(tmpList, index);
        delete tmpList;
    }

    void append(char chr)
    {
        appendItem(new StringItem(chr));
    }

    void append(std::string str)
    {
        int length = str.length();
        for (int i = 0; i < length; i++) {
        	append(str[i]);
        }
    }

    void append(StringList *str)
    {
        appendList(str);
    }

    StringList* concatenate(StringList* str2)
    {
        AbstractList* str1 = createCopy();
        str1->appendList(str2);
        return (StringList*)str1;
    }

    StringList* concatenate(std::string str2)
    {
        AbstractList* str1 = createCopy();
        ((StringList*)str1)->append(str2);
        return (StringList*)str1;
    }
};