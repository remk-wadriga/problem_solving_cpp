#include <iostream>
#include "./CharEntity.cpp"

using namespace std;

// Declare new type;
typedef char* ArrayStringNullByte;
typedef char* ArrayStringSizeByte;
typedef CharEntity* ArrayStringList;

ArrayStringNullByte createFromStringNullByte(string str)
{
    int length = str.length();
    ArrayStringNullByte res = new char[length + 1];
    for (int i = 0; i < length; i++) {
    	res[i] = str[i];
    }
    res[length] = 0;
    return res;
}
ArrayStringSizeByte createFromStringSizeByte(string str)
{
    int length = str.length();
    ArrayStringSizeByte res = new char[length + 1];
    res[0] = length;
    for (int i = 1; i <= length; i++) {
        res[i] = str[i - 1];
    }
    return res;
}

int strLengthNullByte(ArrayStringNullByte str)
{
    int length = 0;
    while (str[length] != 0) {
        length++;
    }
    return length;
}
int strLengthSizeByte(ArrayStringSizeByte str)
{
    return str != NULL ? str[0] : 0;
}

void printStringNullByte(ArrayStringNullByte str)
{
    for (int i = 0; i < strLengthNullByte(str); i++) {
    	cout << str[i];
    }
    cout << "\n";
}
void printStringSizeByte(ArrayStringSizeByte str)
{
    for (int i = 1; i <= strLengthSizeByte(str); i++) {
    	cout << str[i];
    }
    cout << "\n";
}

char characterAtNullByte(const ArrayStringNullByte str, const int pos)
{
    if (pos >= strLengthNullByte(str)) {
        return 0;
    }
    return str[pos];
}
char characterAtSizeByte(const ArrayStringSizeByte str, const int pos)
{
    if (pos >= strLengthSizeByte(str)) {
        return 0;
    }
    return str[pos + 1];
}

bool compareStringsNullByte(ArrayStringNullByte str1, ArrayStringNullByte str2)
{
    int strLen = strLengthNullByte(str1);
    if (strLen != strLengthNullByte(str2)) {
        return false;
    }
    for (int i = 0; i < strLen; i++) {
    	if (str1[i] != str2[i]) {
    	    return false;
    	}
    }
    return true;
}
bool compareStringsSizeByte(ArrayStringSizeByte str1, ArrayStringSizeByte str2)
{
    int strLen = strLengthSizeByte(str1);
    if (strLen != strLengthSizeByte(str2)) {
        return false;
    }
    for (int i = 1; i <= strLen; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}

void appendNullByte(ArrayStringNullByte &str, const char chr)
{
    int i = 0, length = strLengthNullByte(str);
    ArrayStringNullByte newStr = new char[length + 2];
    for (i; i < length; i++) {
    	newStr[i] = characterAtNullByte(str, i);
    }
    newStr[i++] = chr;
    newStr[i] = 0;
    delete[] str;
    str = newStr;
}
void appendSizeByte(ArrayStringSizeByte &str, const char chr)
{
    int i = 1, length = strLengthSizeByte(str);
    ArrayStringSizeByte newStr = new char[length + 2];
    newStr[0] = length + 1;
    for (i; i <= length; i++) {
    	newStr[i] = str[i];
    }
    newStr[i] = chr;
    delete[] str;
    str = newStr;
}

void concatenateNullByte(ArrayStringNullByte &startStr, ArrayStringNullByte endStr)
{
    int length = strLengthNullByte(endStr);
    for (int i = 0; i < length; i++) {
        appendNullByte(startStr, characterAtNullByte(endStr, i));
    }
}
void concatenateSizeByte(ArrayStringSizeByte &startStr, ArrayStringSizeByte endStr)
{
    int length = strLengthSizeByte(endStr);
    for (int i = 0; i < length; i++) {
        appendSizeByte(startStr, characterAtSizeByte(endStr, i));
    }
}

ArrayStringNullByte substringNullByte(ArrayStringNullByte str, int start, int length)
{
    int maxLength = strLengthNullByte(str);
    if (start + length > maxLength) {
        length = maxLength - start;
    }
    ArrayStringNullByte res = new char[length + 1];
    for (int i = start; i < start + length; i++) {
    	res[i - start] = str[i];
    }
    res[length] = 0;
    return res;
}
ArrayStringSizeByte substringSizeByte(ArrayStringSizeByte str, int start, int length)
{
    int maxLength = strLengthSizeByte(str);
    if (start + length > maxLength) {
        length = maxLength - start;
    }
    ArrayStringSizeByte res = new char[length + 2];
    res[0] = length;
    for (int i = start + 1; i <= start + length; i++) {
    	res[i - start] = str[i];
    }
    return res;
}

void stringReplaceNullByte(ArrayStringNullByte &str, ArrayStringNullByte target, ArrayStringNullByte replace)
{
    int stringLength = strLengthNullByte(str), targetLength = strLengthNullByte(target), replaceLength = strLengthNullByte(replace), resLength = 0;
    ArrayStringNullByte tmpRes = new char[stringLength * replaceLength];

    for (int i = 0; i < stringLength; i++) {
        ArrayStringNullByte substr = substringNullByte(str, i, targetLength);
        if (!compareStringsNullByte(substr, target)) {
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
    str = substringNullByte(tmpRes, 0, resLength);
    delete[] tmpRes;
}
void stringReplaceSizeByte(ArrayStringSizeByte &str, ArrayStringSizeByte target, ArrayStringSizeByte replace)
{
    int stringLength = strLengthSizeByte(str), targetLength = strLengthSizeByte(target), replaceLength = strLengthSizeByte(replace), resLength = 1;
    ArrayStringSizeByte tmpRes = new char[stringLength * replaceLength];
    tmpRes[0] = 0;

    for (int i = 1; i <= stringLength; i++) {
        ArrayStringSizeByte substr = substringSizeByte(str, i - 1, targetLength);
        if (!compareStringsSizeByte(substr, target)) {
            tmpRes[resLength++] = str[i];
            delete[] substr;
            continue;
        }

        for (int j = 1; j <= replaceLength; j++) {
        	tmpRes[resLength++] = replace[j];
        }
        i += targetLength - 1;
        delete[] substr;
    }
    tmpRes[0] = resLength - 1;

    delete[] str;
    str = substringSizeByte(tmpRes, 0, resLength);
    delete[] tmpRes;
}

void demonstrateStrings4()
{

}