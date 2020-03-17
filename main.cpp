#include <iostream>
#include "./helpers/IntegerHelper.cpp"
#include "./helpers/StringHelper.cpp"
#include "./chapter_2/figuresPainting.cpp"
#include "./chapter_2/messageDecoding.cpp"

int main()
{
    using namespace std;

    /*long dec1 = 87342345435656;
    cout << "dec2bin: " << dec1 << " => " << dec2bin(dec1) << "\n";
    cout << "\n";*/

    long dec2 = 87342345435656;
    cout << "dec2hex: " << dec2 << " => " << dec2hex(dec2) << "\n";

    /*string bin = "10011110110111111111001011110010011101000001000";
    cout << "bin2dec: " << bin << " => " << bin2dec(bin) << "\n";
    cout << "\n";*/

    /*string hex = "4f6ff9793a08";
    cout << "hex2dec: " << hex << " => " << hex2dec(hex) << "\n";
    cout << "\n";*/

    return 0;
}