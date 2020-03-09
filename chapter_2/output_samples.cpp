// Prints something like this:
// ###
// ##
// #
void print_half_of_square(int size)
{
    using namespace std;
    for (int row = size; row > 0; row--) {
        for (int line = 0; line < row; line++) {
            cout << "#";
        }
        cout << "\n";
    }
}

// Prints something like this:
// #
// ##
// ###
// ##
// #
void print_isosceles_triangle(int size)
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

