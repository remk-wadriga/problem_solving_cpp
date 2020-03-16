#include <iostream>
#include "./helpers/IntegerHelper.cpp"
#include "./helpers/StringHelper.cpp"
#include "./chapter_2/figuresPainting.cpp"
#include "./chapter_2/messageDecoding.cpp"

int main()
{
    using namespace std;

    for (int i = 3; i <= 9; i++) {
        cout << i << "\n";
    	printFatX(i);
        cout << "\n";
    }

    return 0;
}