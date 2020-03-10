/* Prints something like this:
* ###
* ##
* #
*/
void print_half_of_square_right_1(int size)
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
void print_half_of_square_left_1(int size)
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
void print_half_of_square_right_2(int size)
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
void print_half_of_square_left_2(int size)
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
void print_triangle_right(int size)
{
    using namespace std;
    int double_size = size*2;

    for (int row = 1; row < double_size; row++) {
        //int row_length = row <= size ? row : double_size - row;
        int row_length = size - abs(size - row);
        for (int line = 0; line < row_length; line++) {
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
void print_triangle_left(int size)
{
    using namespace std;
    int double_size = size * 2;
    for (int row = 1; row < double_size; row++) {
    	int spaces_count = abs(size - row);
        int grids_count = size - spaces_count;
        for (int spaces = 0; spaces < spaces_count; spaces++) {
            cout << " ";
        }
        for (int grids = 0; grids < grids_count; grids++) {
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
void print_triangle_top(int size)
{
    using namespace std;
    int rest = size % 2;
    int height = size / 2 + rest;

    for (int row = 1; row <= height; row++) {
    	int spaces_count = height - row;
        int grids_count = row * 2 - rest;
        for (int spaces = 0; spaces < spaces_count; spaces++) {
            cout << " ";
        }
        for (int grids = 0; grids < grids_count; grids++) {
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
void print_triangle_down(int size)
{
    using namespace std;
    int height = size / 2 + size % 2;

    for (int row = 0; row < height; row++) {
        int spaces_count = row;
        int grids_count = size - row * 2;
        for (int spaces = 0; spaces < spaces_count; spaces++) {
            cout << " ";
        }
        for (int grids = 0; grids < grids_count; grids++) {
            cout << "#";
        }
        cout << "\n";
    }
}