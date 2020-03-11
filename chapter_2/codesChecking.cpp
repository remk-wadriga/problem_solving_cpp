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