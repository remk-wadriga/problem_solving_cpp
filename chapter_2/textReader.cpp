#include <iostream>

void calculateTextStatistics()
{
    using namespace std;

    string word, lastWord = "", longestWord, shortestWord;
    char symbol;
    int length = 0, wordsCount = 0, symbolsCount = 0, longestLength = 0, shortestLength = 0;

    cin >> word;
    length = word.length();
    while (lastWord != word) {
        wordsCount++;
        symbolsCount += length;
        if (length <= shortestLength || shortestLength == 0) {
            shortestWord = word;
            shortestLength = length;
        } else if (length >= longestLength) {
            longestWord = word;
            longestLength = length;
        }

        cout << word << "\n";
        lastWord = word;
        cin >> word;
        length = word.length();
    }

    cout << "Words count: " << wordsCount << "\n";
    cout << "Symbols count: " << symbolsCount << "\n";
    cout << "Average symbols count: " << symbolsCount / wordsCount << "\n";
    cout << "Longest word: " << longestWord << " (" << longestLength << ")\n";
    cout << "Shortest word: " << shortestWord << " (" << shortestLength << ")\n";
}