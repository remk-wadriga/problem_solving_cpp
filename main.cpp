#include <iostream>
#include "./chapter_2/figuresPainting.cpp"
#include "./chapter_2/codesChecking.cpp"

int main()
{
    using namespace std;

    //printHalfOfSquareRight1(5);
    //printHalfOfSquareLeft1(5);
    //printHalfOfSquareRight2(5);
    //printHalfOfSquareLeft2(5);

    //printTriangleRight(5);
    //printTriangleLeft(5);
    //printTriangleTop(5);
    //printTriangleDown(5);

    // luhnCheckCodeSumInt(1762483)
    /*if (luhnCheckCodeSumString()) {
        cout << "\n";
        cout << "Correct code!" << "\n";
    } else {
        cout << "\n";
        cout << "Incorrect code!" << "\n";
    }*/

    luhnCheckCodeSumString();

    return 0;
}