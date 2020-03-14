#include <iostream>
#include "./helpers/IntegersHelper.cpp"
#include "./chapter_2/figuresPainting.cpp"
#include "./chapter_2/messageDecoding.cpp"

int main()
{
    using namespace std;

    for (int i = 3; i <= 9; i++) {
    	printEmptyRhombus(i);
        cout << "\n";
    }

    return 0;
}