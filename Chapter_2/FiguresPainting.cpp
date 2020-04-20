#include <iostream>

/* Prints something like this:
* ###
* ##
* #
*/
void printHalfOfSquareRight1(int size)
{
    using namespace std;

    for (int row = size; row > 0; row--) {
        cout << stringRepeat("#", row) << "\n";
    }
}

/* Prints something like this:
* ###
*  ##
*   #
*/
void printHalfOfSquareLeft1(int size)
{
    using namespace std;

    for (int row = 0; row < size; row++) {
    	cout << stringRepeat(" ", row) << stringRepeat("#", size - row) << "\n";
    }
}

/* Prints something like this:
* #
* ##
* ###
*/
void printHalfOfSquareRight2(int size)
{
    using namespace std;

    for (int row = 1; row <= size; row++) {
    	cout << stringRepeat("#", row) << "\n";
    }
}

/* Prints something like this:
*   #
*  ##
* ###
*/
void printHalfOfSquareLeft2(int size)
{
    using namespace std;

    for (int row = 1; row <= size; row++) {
        cout << stringRepeat(" ", size - row) << stringRepeat("#", row) << "\n";
    }
}


/** Prints something like this:
* #
* ##
* ###
* ##
* #
*/
void printTriangleRight(int size)
{
    using namespace std;
    int height = size * 2;

    for (int row = 1; row < height; row++) {
        cout << stringRepeat("#", size - abs(size - row)) << "\n";
    }
}

/** Prints something like this:
*   #
*  ##
* ###
*  ##
*   #
*/
void printTriangleLeft(int size)
{
    using namespace std;
    int height = size * 2;
    int spCount = 0, hsCount = 0;

    for (int row = 1; row < height; row++) {
    	int spCount = abs(size - row);
        int hsCount = size - spCount;
        cout << stringRepeat(" ", spCount) << stringRepeat("#", hsCount) << "\n";
    }
}

/** Prints something like this:
*    #
*   ###
*  #####
*/
void printTriangleTop(int size)
{
    using namespace std;
    int modSize = size % 2;
    int height = size / 2 + modSize;
    int spCount = 0, hsCount = 0;

    for (int row = 1; row <= height; row++) {
    	spCount = height - row;
        hsCount = row * 2 - modSize;
        cout << stringRepeat(" ", spCount) << stringRepeat("#", hsCount) << "\n";
    }
}

/** Prints something like this:
*  #####
*   ###
*    #
*/
void printTriangleDown(int size)
{
    using namespace std;
    int height = size / 2 + size % 2;

    for (int row = 0; row < height; row++) {
        cout << stringRepeat(" ", row) << stringRepeat("#", size - row * 2) << "\n";
    }
}


/** Prints something like this:
*    #
*   ###
*  #####
*   ###
*    #
*/
void printRhombus(int size)
{
    using namespace std;
    int modSize = size % 2;
    int height = size - 1 + modSize;
    int spCount = 0, hsCount = 0;
    cout << "Height: " << height << "\n";

    for (int row = 0; row < height; row++) {
        spCount = abs(size / 2 - row - 1 + modSize);
        hsCount = size - spCount * 2;
        cout << stringRepeat(" ", spCount) << stringRepeat("#", hsCount) << "\n";
    }
}


/** Prints something like this:
*  #####
*   ###
*    #
*   ###
*  #####
*/
void printHourglass(int size)
{
    using namespace std;
    int modSize = size % 2;
    int height = size - 1 + modSize;
    int spCount = 0, hsCount = 0;

    for (int row = 0; row < height; row++) {
    	spCount = height / 2 - abs(height / 2 - row);
        hsCount = size - spCount * 2;
        cout << stringRepeat(" ", spCount) << stringRepeat("#", hsCount);
        cout << "     " << row << ": " << spCount << " " << hsCount;
        cout << "\n";
    }
}

/** Prints something like this:
*    #
*   # #
*  #   #
*   # #
*    #
*/
void printEmptyRhombus(int size)
{
    using namespace std;
    int modSize = size % 2;
    int height = size - 1 + modSize;
    int sp1Count = 0, sp2Count = 0;
    cout << "Height: " << height << "\n";

    for (int row = 0; row < height; row++) {
        sp1Count = abs(size / 2 - row - 1 + modSize);
        sp2Count = size - sp1Count * 2 - 2;
        cout << stringRepeat(" ", sp1Count) << "#" << stringRepeat(" ", sp2Count);
        if (modSize == 0 || sp2Count > 0) {
            cout << "#";
        }
        cout << "\n";
    }
}

/** Prints something like this:
*  #   #
*   # #
*    #
*   # #
*  #   #
*/
void printX(int size)
{
    using namespace std;
    int modSize = size % 2;
    int height = size - 1 + modSize;
    int sp1Count = 0, sp2Count = 0;

    for (int row = 0; row < height; row++) {
        sp1Count = height / 2 - abs(height / 2 - row);
        sp2Count = size - sp1Count * 2 - 2;
        cout << stringRepeat(" ", sp1Count) << "#" << stringRepeat(" ", sp2Count);
        if (modSize == 0 || sp2Count > 0) {
            cout << "#";
        }
        cout << "\n";
    }
}

/** Prints something like this:
* #         #
*  ##     ##
*   ### ###
*    #####
*   ### ###
*  ##     ##
* #         #
*/
void printFatX(int size)
{
    using namespace std;

    int modSize = size % 2;
    int width = size * 2 + 2 - modSize;
    int height = size + 3 - modSize;
    int midHeight = height / 2;
    int sp1Count = 0, rowWidth = 0, hs1Count = 0, sp2Count = 0, hs2Count = 0;

    for (int row = 0; row < height; row++) {
        sp1Count = height / 2 - abs(height / 2 - row);
        rowWidth = width - sp1Count * 2;
        if (row == midHeight) {
            hs1Count = size;
            sp2Count = hs2Count = 0;
        } else {
            hs1Count = sp1Count + 1;
            sp2Count = abs(rowWidth - hs1Count * 2) - modSize + modSize;
            hs2Count = rowWidth - hs1Count - sp2Count;
        }
        cout << stringRepeat(" ", sp1Count) << stringRepeat("#", hs1Count) << stringRepeat(" ", sp2Count) << stringRepeat("#", hs2Count) << "\n";
    }
}
