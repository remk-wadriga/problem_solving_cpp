#include <iostream>

typedef NumInList* NumList;

int unsignedPow(int base, int pow)
{
    int result = 1;
    for (int i = 1; i <= pow; i++) {
    	result *= base;
    }
    return result;
}

int str2int(std::string code)
{
    int codeLength = code.length();
    int result = 0;
    for (int i = 0; i < codeLength; i++) {
    	result = result * 10 + (code[i] - '0');
    }
    return result;
}

/**
* 4 => 100
* 15 => 1111
* 124 => 1111100
* 256 => 100000000
* 2345678 => 1000111100101011001110
* 87342345435656 => 10011110110111111111001011110010011101000001000
*/
std::string dec2bin (long dec)
{
    using namespace std;
    string bin = "";
    long rest = 0;

    while (dec > 0) {
        rest = dec % 2;
        dec /= 2;
        bin = to_string(rest) + bin;
    }

    return bin;
}

/**
* 4 => 4
* 15 => f
* 124 => 7c
* 256 => 100
* 2345678 => 23cace
* 87342345435656 => 4f6ff9793a08
*/
std::string dec2hex (long dec)
{
    using namespace std;
    string hex = "";
    long rest = 0;
    string intVal;

    while (dec > 0) {
        rest = dec % 16;
        dec /= 16;
        switch (rest) {
            case 10:
                intVal = "A";
                break;
            case 11:
                intVal = "B";
                break;
            case 12:
                intVal = "C";
                break;
            case 13:
                intVal = "D";
                break;
            case 14:
                intVal = "E";
                break;
            case 15:
                intVal = "F";
                break;
            default:
                intVal = to_string(rest);
                break;
        }

        hex = intVal + hex;
    }

    return hex;
}

/**
* 100 => 4
* 1111 => 15
* 1111100 => 124
* 100000000 => 256
* 1000111100101011001110 => 2345678
* 10011110110111111111001011110010011101000001000 => 87342345435656
*/
long bin2dec (std::string bin)
{
    using namespace std;
    long dec = 0;
    int length = bin.length();
    int intVal = 0;

    for (int i = 0; i < length; i++) {
    	intVal = bin[i] - '0';
    	dec = dec * 2 + intVal;
    }

    return dec;
}

/**
* 4 => 4
* f => 15
* 7c => 124
* 100 => 256
* 23cace => 2345678
* 4f6ff9793a08 => 87342345435656
*/
long hex2dec (std::string hex)
{
    using namespace std;
    long dec = 0;
    int length = hex.length();
    int intVal = 0;

    for (int i = 0; i < length; i++) {
        intVal = (hex[i] >= 'A') ? (hex[i] >= 'a') ? (hex[i] - 'a' + 10) : (hex[i] - 'A' + 10) : (hex[i] - '0');
        dec = dec * 16 + intVal;
    }

    return dec;
}

NumList intToList(int base)
{
    NumInList* firstElem = new NumInList;
    firstElem->val = base % 10;
    firstElem->next = NULL;

    int pervVal = base / 10;
    while (pervVal > 0) {
        NumInList* prevElem = new NumInList;
        prevElem->val = pervVal % 10;
        prevElem->next = firstElem;
        firstElem = prevElem;
        pervVal /= 10;
    }

    return firstElem;
}

NumList numListsSum(NumList list1, NumList list2)
{
    return intToList(list1->toInt() + list2->toInt());
}

NumList numListsSumOfNumbers(NumList list1, NumList list2)
{
    int res = 0;
    NumInList* firstElem1 = list1;
    NumInList* firstElem2 = list2;
    while (firstElem1 != NULL || firstElem2 != NULL) {
        res += firstElem1->val + firstElem2->val;
        if (firstElem1 != NULL) {
            firstElem1 = firstElem1->next;
        }
        if (firstElem2 != NULL) {
            firstElem2 = firstElem2->next;
        }
    }

    return intToList(res);
}