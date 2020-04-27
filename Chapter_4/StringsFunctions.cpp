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
ArrayStringList createFromStringList(string str)
{
    int length = str.length();
    CharEntity* firstEntity = new CharEntity;
    firstEntity->val = 0;
    firstEntity->next = NULL;
    if (length == 0) {
        return firstEntity;
    }

    firstEntity->val = str[0];
    CharEntity* entity = firstEntity;

    for (int i = 1; i < length; i++) {
        CharEntity* nextEntity = new CharEntity;
        nextEntity->val = str[i];
        nextEntity->next = NULL;
        entity->next = nextEntity;
        entity = nextEntity;
    }

    return firstEntity;
}
CharEntity* createStringEntityFromChar(char chr, CharEntity* next = NULL)
{
    CharEntity* entity = new CharEntity;
    entity->val = chr;
    entity->next = next;
    return entity;
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
int strLengthList(ArrayStringList list)
{
    int size = 0;
    CharEntity* entity = list;
    while (entity != NULL) {
        size++;
        entity = entity->next;
    }
    return size;
}

void printStringNullByte(ArrayStringNullByte str, bool withSize = true)
{
    int size = strLengthNullByte(str);
    for (int i = 0; i < size; i++) {
    	cout << str[i];
    }
    if (withSize && size > 0) {
        cout << " (" << size << ")";
    }
    cout << "\n";
}
void printStringSizeByte(ArrayStringSizeByte str, bool withSize = true)
{
    int size = strLengthSizeByte(str);
    for (int i = 1; i <= strLengthSizeByte(str); i++) {
    	cout << str[i];
    }
    if (withSize && size > 0) {
        cout << " (" << size << ")";
    }
    cout << "\n";
}
void printStringList(ArrayStringList list, bool withSize = true)
{
    int size = 0;
    CharEntity* entity = list;
    while (entity != NULL) {
        size++;
        cout << entity->val;
        entity = entity->next;
    }
    if (withSize && size > 0) {
        cout << " (" << size << ")";
    }
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
CharEntity* entityAtList(const ArrayStringList list, const int pos)
{
    if (strLengthList(list) <= pos) {
        return NULL;
    }
    CharEntity* entity = list;
    if (entity == NULL) {
        return entity;
    }
    int index = 0;
    while (entity->next != NULL && index++ < pos) {
        entity = entity->next;
    }
    return entity;
}
char characterAtList(const ArrayStringList list, const int pos)
{
    CharEntity* entity = entityAtList(list, pos);
    return entity != NULL ? entity->val : 0;
}

void deleteEntityFromList(ArrayStringList &list, const int pos)
{
    CharEntity* currentEntity = list;
    CharEntity* lastEntity = NULL;
    CharEntity* firstEntity = NULL;

    if (pos == 0) {
        firstEntity = currentEntity != NULL ? currentEntity->next : NULL;
        delete currentEntity;
        list = firstEntity;
        return;
    }

    int number = 0;
    while (currentEntity != NULL && lastEntity == NULL) {
        if (number++ == pos - 1) {
            lastEntity = currentEntity;
        }
        currentEntity = currentEntity->next;
    }

    if (lastEntity == NULL || lastEntity->next == NULL) {
        return;
    }

    currentEntity = lastEntity->next;
    firstEntity = currentEntity->next;

    lastEntity->next = firstEntity;
    delete currentEntity;
}
CharEntity* getLastEntityFromList(ArrayStringList list)
{
    CharEntity* lastEntity = list;
    if (lastEntity == NULL) {
        return lastEntity;
    }
    while (lastEntity->next != NULL) {
        lastEntity = lastEntity->next;
    }
    return lastEntity;
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
bool compareStringsList(ArrayStringList list1, ArrayStringList list2)
{
    if (list1 == list2) {
        return true;
    }
    int list1Length = strLengthList(list1), list2Length = strLengthList(list2);
    if (list1Length != list2Length) {
        return false;
    }

    for (int i = 0; i < list1Length; i++) {
    	if (list1->val != list2->val) {
    	    return false;
    	}
    	list1 = list1->next;
    	list2 = list2->next;
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
void appendList(ArrayStringList &list, const char chr)
{
    CharEntity* newEntity = createStringEntityFromChar(chr);

    CharEntity* lastEntity = getLastEntityFromList(list);
    if (lastEntity == NULL) {
        list = newEntity;
        return;
    }

    lastEntity->next = newEntity;
}

void removeCharsNullByte(ArrayStringNullByte &str, const int from, const int length)
{
    if (length <= 0) {
        return;
    }
    int strLength = strLengthNullByte(str);
    if (from >= strLength) {
        return;
    }

    int resLength = strLength - (strLength - from >= length ? length : strLength - from) + 1;
    if (resLength == 0) {
        delete[] str;
        str = NULL;
        return;
    }

    ArrayStringNullByte res = new char[resLength];
    int j = 0;
    for (int i = 0; i < from; i++) {
    	res[j++] = str[i];
    }
    for (int i = from + strLength - resLength + 1; i < strLength; i++) {
    	res[j++] = str[i];
    }
    res[resLength] = 0;

    delete[] str;
    str = res;
}
void removeCharsSizeByte(ArrayStringSizeByte &str, const int from, const int length)
{
    if (length <= 0) {
        return;
    }
    int strLength = strLengthSizeByte(str);
    if (from >= strLength) {
        return;
    }

    int resLength = strLength - (strLength - from >= length ? length : strLength - from) + 1;
    if (resLength == 0) {
        delete[] str;
        str = NULL;
        return;
    }

    ArrayStringSizeByte res = new char[resLength];

    res[0] = resLength - 1;
    int j = 1;
    for (int i = 1; i <= from; i++) {
    	res[j++] = str[i];
    }
    for (int i = from + strLength - resLength + 2; i <= strLength; i++) {
        res[j++] = str[i];
    }

    delete[] str;
    str = res;
}
void removeCharsList(ArrayStringList &list, const int from, const int length)
{
    if (length <= 0 || list == NULL) {
        return;
    }
    CharEntity* lastEntity = list;
    for (int i = 0; i < from - 1 && lastEntity != NULL; i++) {
    	lastEntity = lastEntity->next;
    }
    if (lastEntity == NULL) {
        return;
    }

    CharEntity* firstEntity = from > 0 ? lastEntity->next : lastEntity;
    CharEntity* tmpEntity = firstEntity;
    for (int i = 0; i < length && firstEntity != NULL; i++) {
    	firstEntity = firstEntity->next;
    	delete tmpEntity;
    }
    if (from > 0) {
        lastEntity->next = firstEntity;
    } else {
        delete lastEntity;
        delete list;
        list = firstEntity;
    }
}

void deleteStringList(ArrayStringList &list)
{
    int size = strLengthList(list);
    for (int i = size - 1; i >= 0; i--) {
    	CharEntity* lastEntity = entityAtList(list, i);
    	lastEntity->val = 0;
    	lastEntity->next = NULL;
    	delete lastEntity;
    }
    list = NULL;
}
ArrayStringList copyStringList(ArrayStringList list)
{
    ArrayStringList res = NULL;
    if (list == NULL) {
        return res;
    }

    CharEntity* entity = list;
    appendList(res, entity->val);
    while (entity->next != NULL) {
        entity = entity->next;
        appendList(res, entity->val);
    }
    return res;
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
void concatenateList(ArrayStringList &list1, ArrayStringList list2)
{
    CharEntity* entity = list2;
    while (entity != NULL) {
        appendList(list1, entity->val);
        entity = entity->next;
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
ArrayStringList substringList(ArrayStringList list, int start, int length)
{
    CharEntity* firstEntity = createStringEntityFromChar(0);
    if (length == 0) {
        return firstEntity;
    }
    char chr = characterAtList(list, start);
    firstEntity->val = chr;

    CharEntity* entity = firstEntity;
    for (int i = start + 1; i < start + length && chr != 0; i++) {
    	chr = characterAtList(list, i);
    	if (chr == 0) {
    	    break;
    	}
    	CharEntity* nextEntity = createStringEntityFromChar(chr);
        entity->next = nextEntity;
        entity = nextEntity;
    }

    return firstEntity;
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
void stringReplaceList(ArrayStringList &list, ArrayStringList target, ArrayStringList replace)
{
    int stringLength = strLengthList(list), targetLength = strLengthList(target);
    if (stringLength == 0) {
        return;
    }

    ArrayStringList res = new CharEntity;
    for (int i = 0; i < stringLength; i++) {
    	ArrayStringList substr = substringList(list, i, targetLength);

    	if (!compareStringsList(substr, target)) {
            appendList(res, characterAtList(list, i));
            deleteStringList(substr);
            continue;
    	}

    	ArrayStringList replaceCopy = copyStringList(replace);
    	concatenateList(res, replaceCopy);
    	i += targetLength - 1;

    	deleteStringList(substr);
        deleteStringList(replaceCopy);
    }

    deleteStringList(list);
    list = res;
}

void demonstrateStrings4()
{
    /*ArrayStringList list = createFromStringList("{_i_}Very{_i_}long{_i_}and{_i_}very{_i_}strange{_i_}string{_i_}");
    printStringList(list); cout << "\n";*/

    ArrayStringList str = createFromStringList("ABCDE");
    printStringList(str); cout << "\n";
    cout << "---------------" << "\n";

    removeCharsList(str, 4, 1);

    printStringList(str); cout << "\n";
}