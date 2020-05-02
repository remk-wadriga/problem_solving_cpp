#include <iostream>
#include "./String.cpp"

void demonstrateStrings5()
{
    using namespace std;

    String str1("Test");
    String str2("string");
    String str3("Blablabla");

    str1.remove(0, 4);

    /*str3 = str2;
    str1.concatenate(" ");
    str1.concatenate(str3);*/

    str1.remove(0, 4);

    cout << str1.toString() << "\n";
}