#include <iostream>

std::string stringRepeat(std::string str, int count, std::string delimiter)
{
    using namespace std;
    string result = "";
    int lastPos = count - 1;
    for (int i = 0; i < count; i++) {
    	result += str;
    	if (i != lastPos) {
    	    result += delimiter;
    	}
    }
    return result;
}

std::string stringRepeat(std::string str, int count, char delimiter)
{
    using namespace std;
    string result = "";
    int lastPos = count - 1;
    for (int i = 0; i < count; i++) {
        result += str;
        if (i != lastPos) {
            result.push_back(delimiter);
        }
    }
    return result;
}

std::string stringRepeat(char str, int count, std::string delimiter)
{
    using namespace std;
    string result = "";
    int lastPos = count - 1;
    for (int i = 0; i < count; i++) {
        result.push_back(str);
        if (i != lastPos) {
            result += delimiter;
        }
    }
    return result;
}

std::string stringRepeat(char str, int count, char delimiter)
{
    using namespace std;
    string result = "";
    int lastPos = count - 1;
    for (int i = 0; i < count; i++) {
        result.push_back(str);
        if (i != lastPos) {
            result.push_back(delimiter);
        }
    }
    return result;
}

std::string stringRepeat(std::string str, int count)
{
    using namespace std;
    string result = "";
    for (int i = 0; i < count; i++) {
        result += str;
    }
    return result;
}

std::string stringRepeat(char str, int count)
{
    using namespace std;
    string result = "";
    for (int i = 0; i < count; i++) {
        result.push_back(str);
    }
    return result;
}
