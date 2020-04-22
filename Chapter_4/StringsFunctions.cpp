#include <iostream>

using namespace std;

// Declare new type;
typedef char* ArrayString;

ArrayString createFromString(string str)
{
    int length = str.length();
    ArrayString res = new char[length + 1];
    for (int i = 0; i < length; i++) {
    	res[i] = str[i];
    }
    res[length] = 0;
    return res;
}


int strLength(const ArrayString str)
{
    int length = 0;
    while (str[length] != 0) {
        length++;
    }
    return length;
}

char characterAt(const ArrayString str, const int pos)
{
    return str[pos];
}

void append(ArrayString &str, const char chr)
{
    int i = 0, length = strLength(str);
    ArrayString newStr = new char[length + 2];
    for (i; i < length; i++) {
    	newStr[i] = characterAt(str, i);
    }
    newStr[i++] = chr;
    newStr[i] = 0;
    delete[] str;
    str = newStr;
}

void concatenate(ArrayString &startStr, ArrayString endStr)
{
    int length = strLength(endStr);
    for (int i = 0; i < length; i++) {
        append(startStr, characterAt(endStr, i));
    }
}


void demonstrateStrings4()
{
    ArrayString a = createFromString("");
    ArrayString b = createFromString("test");
    concatenate(a, b);
    cout << "a:" << a << " (" << (void *)a << ")" << "\n";
    cout << "b:" << b << " (" << (void *)b << ")" << "\n";

    /*ArrayString str = createFromString("Hello");

    append(str, ' ');
    concatenate(str, createFromString("World"));
    append(str, '!');

    cout << str << " (" << strLength(str) << ")" << "\n";*/
}