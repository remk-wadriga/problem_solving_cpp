#include <iostream>
#include "./String.cpp"

void demonstrateStrings5()
{
    using namespace std;

    String str1("Test");
    String str2("string");
    String str3("Blablabla");

    str3 = str2;

    str1.concatenate(" ");
    str1.concatenate(str3);

    cout << str1.toString() << "\n";
}