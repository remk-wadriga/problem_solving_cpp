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

bool compareStrings(ArrayString str1, ArrayString str2)
{
    int strLen = strLength(str1);
    if (strLen != strLength(str2)) {
        return false;
    }
    for (int i = 0; i < strLen; i++) {
    	if (str1[i] != str2[i]) {
    	    return false;
    	}
    }
    return true;
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

ArrayString substring(ArrayString str, int start, int length)
{
    int maxLength = strLength(str);
    if (start + length > maxLength) {
        length = maxLength - start;
    }
    ArrayString res = new char[length + 1];
    for (int i = start; i < start + length; i++) {
    	res[i - start] = str[i];
    }
    res[length] = 0;
    return res;
}

void stringReplace(ArrayString &str, ArrayString target, ArrayString replace)
{
    int stringLength = strLength(str), targetLength = strLength(target), replaceLength = strLength(replace), resLength = 0;
    ArrayString tmpRes = new char[stringLength * replaceLength];

    for (int i = 0; i < stringLength; i++) {
        ArrayString substr = substring(str, i, targetLength);
        if (!compareStrings(substr, target)) {
            tmpRes[resLength++] = str[i];
            delete[] substr;
            continue;
        }
        for (int j = 0; j < replaceLength; j++) {
        	tmpRes[resLength++] = replace[j];
        }
        i += targetLength - 1;
        delete[] substr;
    }

    delete[] str;
    str = substring(tmpRes, 0, resLength);
    delete[] tmpRes;
}

void demonstrateStrings4()
{
    /*ArrayString a = createFromString("");
    ArrayString b = createFromString("test");
    concatenate(a, b);
    cout << "a:" << a << " (" << (void *)a << ")" << "\n";
    cout << "b:" << b << " (" << (void *)b << ")" << "\n";*/

    ArrayString str = createFromString("{_1_}Very{_1_}long{_1_}and{_1_}very{_1_}strange{_1_}word{_1_}");
    cout << str << " (" << strLength(str) << ")" << "\n";

    stringReplace(str, createFromString("{_1_}"), createFromString("__"));
    cout << str << " (" << strLength(str) << ")" << "\n";
}