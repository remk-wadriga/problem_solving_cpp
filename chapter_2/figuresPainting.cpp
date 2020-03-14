/* Prints something like this:
* ###
* ##
* #
*/
void printHalfOfSquareRight1(int size)
{
    using namespace std;
    for (int row = size; row > 0; row--) {
        for (int line = 0; line < row; line++) {
            cout << "#";
        }
        cout << "\n";
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
    	for (int spaces = 0; spaces < row; spaces++) {
    		cout << " ";
    	}
    	for (int grids = 0; grids < size - row; grids++) {
            cout << "#";
        }
    	cout << "\n";
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
    	for (int line = 0; line < row; line++) {
    		cout << "#";
    	}
    	cout << "\n";
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
    	for (int spaces = 0; spaces < size - row; spaces++) {
            cout << " ";
        }
        for (int grids = 0; grids < row; grids++) {
            cout << "#";
        }
        cout << "\n";
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
    int doubleSze = size*2;

    for (int row = 1; row < doubleSze; row++) {
        //int rowLength = row <= size ? row : doubleSze - row;
        int rowLength = size - abs(size - row);
        for (int line = 0; line < rowLength; line++) {
            cout << "#";
        }
        cout << "\n";
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
    int doubleSze = size * 2;
    for (int row = 1; row < doubleSze; row++) {
    	int spacesCount = abs(size - row);
        int gridsCount = size - spacesCount;
        for (int spaces = 0; spaces < spacesCount; spaces++) {
            cout << " ";
        }
        for (int grids = 0; grids < gridsCount; grids++) {
            cout << "#";
        }
        cout << "\n";
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
    int rest = size % 2;
    int height = size / 2 + rest;

    for (int row = 1; row <= height; row++) {
    	int spacesCount = height - row;
        int gridsCount = row * 2 - rest;
        for (int spaces = 0; spaces < spacesCount; spaces++) {
            cout << " ";
        }
        for (int grids = 0; grids < gridsCount; grids++) {
            cout << "#";
        }
        cout << "\n";
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
        int spacesCount = row;
        int gridsCount = size - row * 2;
        for (int spaces = 0; spaces < spacesCount; spaces++) {
            cout << " ";
        }
        for (int grids = 0; grids < gridsCount; grids++) {
            cout << "#";
        }
        cout << "\n";
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

    for (int row = 0; row < size; row++) {
        int spCount = abs(size / 2 - row);
        int hsCount = abs(size - spCount * 2);
        for (int i = 0; i < spCount; i++) {
            cout << " ";
        }
        for (int i = 0; i < hsCount; i++) {
            cout << "#";
        }
        cout  << "\n";
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
    int height = size + modSize - 1;
    int spCount = 0;

    for (int row = height; row > 0; row--) {
        if (row >= size / 2 + 1) {
            spCount = size - row;
            if (modSize == 0) {
                spCount--;
            }
        } else {
            spCount = row - 1;
        }
        int hsCount = size - spCount * 2;
        for (int i = 0; i < spCount; i++) {
            cout << " ";
        }
        for (int i = 0; i < hsCount; i++) {
            cout << "#";
        }
        cout << "      " << row << ": " << spCount << " " << hsCount;
        cout  << "\n";
    }
}

/** Prints something like this:
*    #
*   # #
*  #   #
*   # #
*    #
*/
void printEmptyRhombusRow(int row, int size, int height, int modSize)
{
    using namespace std;
    int sp1Count = row;
    int sp2Count = size - sp1Count * 2 - modSize - 1;
    for (int i = 0; i < sp1Count; i++) {
        cout << " ";
    }
    cout << "#";
    for (int i = 0; i < sp2Count; i++) {
        cout << " ";
    }
    if (modSize == 0 || (row < height - 1)) {
        cout << "#";
    }
    cout  << "\n";
}
void printEmptyRhombus(int size)
{
    using namespace std;
    int modSize = size % 2;
    int height = (size - 1 + modSize) / 2 + 1;

    for (int row = height - 1; row >= 0; row--) {
        printEmptyRhombusRow(row, size, height, modSize);
    }
    for (int row = 1; row < height; row++) {
        printEmptyRhombusRow(row, size, height, modSize);
    }
}

/** Prints something like this:
*  #   #
*   # #
*    #
*   # #
*  #   #
*/
void printXRow(int row, int size, int midHeight, int modSize)
{
    using namespace std;
    int sp1Count = row;
    int sp2Count = size - sp1Count * 2 - modSize - 1;
    for (int i = 0; i < sp1Count; i++) {
        cout << " ";
    }
    cout << "#";
    for (int i = 0; i < sp2Count; i++) {
        cout << " ";
    }
    if (modSize == 0 || row != midHeight - 1) {
        cout << "#";
    }
    cout  << "\n";
}
void printX(int size)
{
    using namespace std;
    int modSize = size % 2;
    int halfSize = size / 2;
    int height = size - 1 + modSize;
    int midHeight = height / 2 + 1;

    for (int row = 0; row < midHeight; row++) {
        printXRow(row, size, midHeight, modSize);
    }
    for (int row = midHeight - 2; row >= 0; row--) {
        printXRow(row, size, midHeight, modSize);
    }
}

/** Prints something like this:
* #            #
*  ##        ##
*   ###    ###
*    ########
*    ########
*   ###    ###
*  ##        ##
* #            #
*/
void printFatXRow(int row, int size, int width, int height, int modSize)
{
    using namespace std;
    int sp1Count = row;
    int rowWidth = width - row * 2;
    int hs1Count = 0, sp2Count = 0, hs2Count = 0;
    if (row < height - 1) {
        hs1Count = hs2Count = row + 1;
        sp2Count = rowWidth - hs1Count * 2;
    } else {
        hs1Count = size;
        hs2Count = sp2Count = 0;
    }

    for (int line = 0; line < sp1Count; line++) {
        cout << " ";
    }
    for (int line = 0; line < hs1Count; line++) {
        cout << "#";
    }
    for (int line = 0; line < sp2Count; line++) {
        cout << " ";
    }
    for (int line = 0; line < hs2Count; line++) {
        cout << "#";
    }

    cout << "\n";
}
void printFatX(int size)
{
    using namespace std;

    int modSize = size % 2;
    int width = size * 2 + 2 - modSize;
    int height = size - size / 2 + 2 - modSize;

    for (int row = 0; row < height; row++) {
        printFatXRow(row, size, width, height, modSize);
    }
    for (int row = height - 1; row >= 0; row--) {
        printFatXRow(row, size, width, height, modSize);
    }
}