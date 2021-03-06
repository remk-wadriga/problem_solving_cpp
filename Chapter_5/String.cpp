#include <iostream>

class String
{
public:
    // Default constructor
    String(std::string str)
    {
        _list = NULL;
        Char* lastChar;
        for (int i = 0; i < str.length(); i++) {
            Char* newChar = createFromChar(str[i]);
            if (i == 0) {
               _list = newChar;
               lastChar = newChar;
            } else {
                lastChar->next = newChar;
                lastChar = newChar;
            }
        }
    }

    // Copying constructor
    String(const String &original)
    {
        _list = original._list;
    }

    // Destructor
    ~String()
    {
        deleteList(_list);
    }

    // Reload operator "=" to correct assign an object to variable with with link to another object this type
    String& operator=(const String& rhs)
    {
        if (this == &rhs) {
            return *this;
        }

        deleteList(_list);
        _list = createListCopy(rhs._list);
        return *this;
    }

    // Reload operator "[]" to get chars by index
    char operator[](const int index)
    {
        int i = 0;
        Char* chr = _list;
        while (i < index && chr != NULL) {
            chr = chr->next;
            i++;
        }
        return chr != NULL ? chr->val : '0';
    }

    // Public methods
    std::string toString()
    {
        using namespace std;

        string res = "";
        Char* chr = _list;
        while (chr != NULL) {
            res.push_back(chr->val);
            chr = chr->next;
        }

        return res;
    }

    void appEnd(char chr)
    {
        Char* newChar = createFromChar(chr);
        Char* lastChar = getLastChar();
        if (lastChar == NULL) {
            _list = lastChar = newChar;
        } else {
            lastChar->next = newChar;
        }
    }

    void concatenate(std::string str)
    {
        Char* last = getLastChar();
        for (int i = 0; i < str.length(); i++) {
            Char* newChar = createFromChar(str[i]);
        	if (last == NULL) {
                _list = last = newChar;
            } else {
                last->next = newChar;
                last = newChar;
            }
        }
    }

    void concatenate(const String &str)
    {
        Char* chr = str._list;
        Char* last = getLastChar();
        while (chr != NULL) {
            Char* newChar = createFromChar(chr->val);
            if (last == NULL) {
                _list = last = newChar;
            } else {
                last->next = newChar;
                last = newChar;
            }
            chr = chr->next;
        }
    }

    void remove(int pos, int length)
    {
        using namespace std;
        int i = 0;
        Char* firstChar = _list;
        if (pos > 0) {
            while (i < pos - 1 && firstChar != NULL) {
                firstChar = firstChar->next;
                i++;
            }
        }
        if (firstChar == NULL) {
            return;
        }

        i = 0;
        Char* lastChar = pos > 0 ? firstChar->next : firstChar;
        while (i < length && lastChar != NULL) {
            Char* tmpChar = lastChar;
            lastChar = lastChar->next;
            delete tmpChar;
            i++;
        }

        firstChar->next = lastChar;
        if (pos == 0 && lastChar == NULL) {
            delete firstChar;
            _list = NULL;
        }
    }
    // END Public methods
private:
    struct Char {
        char val;
        Char* next;
    };

    typedef Char* CharsList;

    CharsList _list;

    // Private methods
    Char* createFromChar(char chr)
    {
        Char* newChar = new Char;
        newChar->val = chr;
        newChar->next = NULL;
        return newChar;
    }

    Char* getLastChar()
    {
        if (_list == NULL) {
            return NULL;
        }
        Char* last = _list;
        while (last->next != NULL) {
            last = last->next;
        }
        return last;
    }
    // END Private methods

    void deleteList(CharsList list)
    {
        Char* chr = list;
        while (chr != NULL) {
            Char* tmpChar = chr;
            chr = chr->next;
            delete tmpChar;
        }
    }

    CharsList createListCopy(CharsList originList)
    {
        CharsList newList = NULL;
        Char* lastChar = NULL;
        Char* chr = originList;
        while (chr != NULL) {
            Char* newChar = createFromChar(chr->val);
            chr = chr->next;
            if (newList == NULL) {
                newList = newChar;
                lastChar = newChar;
            } else {
                lastChar->next = newChar;
                lastChar = newChar;
            }
        }
        return newList;
    }
};