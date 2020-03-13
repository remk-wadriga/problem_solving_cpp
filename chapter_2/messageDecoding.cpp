#include <iostream>

/**
*# Прочитать посимвольно закодированное сообщение, которое содержит последовательность положительных целых чисел, разделённых запятыми.
*# Реализовать 3 способа (режима) декодирования: верхний регистр (uppercase), нижний регистр (lowercase) и пунктуация (punctuation):
*    - Верхний регистр (uppercase). Каждое число, взятое по модулю 27 представляет букву в верхнем регистре (1 - А и т. д.);
*    - Нижний регистр (lowercase). То же самое, что в режиме верхнего регистра, но буквы строчные:
*    - Пунктуация (punctuation). Каждое число, взтое по модулю 9, означает символ согласно таблице.
*# В начале каждого сообщения устанавливается режим декодирования.
*# Каждый раз, когда число по модулю 27 или 9 равно 0, переключается режим декодирования:
*    - uppercase -> lowercase
*    - lowercase -> punctuation
*    - punctuation -> uppercase
*# Таблица пунктуации:
*    1 -> !
*    2 -> ?
*    3 -> ,
*    4 -> .
*    5 -> (пробел)
*    6 -> ;
*    7 -> "
*    8 -> '
*
*# План:
* 1. Реализовать посимвольное чтение из коносли. +
* 2. Реализовать посимвольное чтение из файла. +
* 3. Различать режим декодирования, указанный вначале, разделители и кодовые числа. +
* 4. Реализовать ф-ю взятия по модулю для каждого из режимов. +
* 5. Реализовать механизм переключения между режимами (в зависимости от того, что вернула ф-я 4). +
* 6. Реализовать все 3 механизма декодирования символов. +
*/

const std::string MODE_UPPERCASE = "000";
const std::string MODE_LOWERCASE = "001";
const std::string MODE_PUNCTUATION = "002";

const char UPPERCASE_TABLE[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const char LOWERCASE_TABLE[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
const char PUNCTUATION_TABLE[8] = {'!', '?', ',', '.', ' ', ';', '"', '\''};

int getModule(int x, std::string mode)
{
    int result;
    if (mode == MODE_UPPERCASE) {
        result = x % 27;
    } else if (mode == MODE_LOWERCASE) {
        result = x % 27;
    } else if (mode == MODE_PUNCTUATION) {
        result = x % 9;
    } else {
        std::cout << "Invalid mode: \"" << mode << "\"!\n";
    }
    return result;
}

std::string switchMode(std::string mode)
{
    std::string result;
    if (mode == MODE_UPPERCASE) {
        result = MODE_LOWERCASE;
    } else if (mode == MODE_LOWERCASE) {
        result = MODE_PUNCTUATION;
    } else if (mode == MODE_PUNCTUATION) {
        result = MODE_UPPERCASE;
    } else {
        std::cout << "Invalid mode: \"" << mode << "\"!\n";
    }
    return result;
}

char decodeNumber(int number, std::string mode)
{
    char result;
    if (mode == MODE_UPPERCASE) {
        //result = UPPERCASE_TABLE[number - 1];
        result = 'A' + (number - 1);
    } else if (mode == MODE_LOWERCASE) {
        //result = LOWERCASE_TABLE[number - 1];
        result = 'a' + (number - 1);
    } else if (mode == MODE_PUNCTUATION) {
        result = PUNCTUATION_TABLE[number - 1];
    } else {
        std::cout << "Invalid mode: \"" << mode << "\"!\n";
    }
    return result;
}

/**
* g++ main.cpp && ./a.out < ./chapter_2/encoded_message.key
*/
void decode()
{
    using namespace std;

    // Get code-string from console or from file if it's given
    string code;
    cin >> code;

    // Identify decoding - first 3 symbols of code and remove them from code
    string mode = code.substr(0, 3);
    code.erase(0, 3);

    // Get code length and create tmp var for holding code-number string values
    int codeLength = code.length();
    string decodedString = "";
    int number = 0, module = 0;
    for (int i = 0; i < codeLength; i++) {
    	// This is end of number, so...
    	if (code[i] == ',' || i + 1 == codeLength) {
    	    // calculate the module of number
            module = getModule(number, mode);
            if (module == 0) {
                // switch mode if needed
                mode = switchMode(mode);
            } else {
                // or get decoded symbol and add it to end of decoded string
                decodedString.push_back(decodeNumber(module, mode));
            }
            // and set next number to 0
            number = 0;
    	} else {
    	    // This is part of number, so add it to number
    	    number = number * 10 + (code[i] - '0');
    	}
    }

    cout << "Decoded string: " << decodedString << "\n";
}