#include <iostream>
using namespace std;

class Encoder
{
    private:
        const static int SYMBOLS_COUNT = 70;

        char SYMBOLS[SYMBOLS_COUNT] = {
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
            '!', '?', ',', '.', ' ', ';', '"', '\''
        };

        string text;

        int transformIndex(int index)
        {
            return SYMBOLS_COUNT - index - 1;
        }

    public:
        Encoder(string inputText)
        {
            text = inputText;
            randomizeArray(SYMBOLS, SYMBOLS_COUNT);
        }

        string encode()
        {
            string code = "";

            for (int i = 0; i < text.length(); i++) {
                int symbolIndex = indexOf(text[i], SYMBOLS, SYMBOLS_COUNT);
                code.push_back(SYMBOLS[transformIndex(symbolIndex)]);
            }

            return code;
        }

        string decode()
        {
            string message = "";
            for (int i = 0; i < text.length(); i++) {
                int symbolIndex = indexOf(text[i], SYMBOLS, SYMBOLS_COUNT);
                message.push_back(SYMBOLS[transformIndex(symbolIndex)]);
            }

            return message;
        }
};