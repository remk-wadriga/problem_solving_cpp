#include <iostream>
#include "../lib/Numeral.cpp"

int calculateDoubleSumValue(int number)
{
    number *= 2;
    return number > 9 ? 1 + number % 10 : number;
}

bool luhnCheckCodeSumInt(int code)
{
    using namespace std;
    int step = 0;
    int checkSum = 0;

    Numeral numeralCode = Numeral(code);

    for (int num : numeralCode.getNumbers()) {
        if (step % 2 == 1 && step + 1 < numeralCode.size()) {
            checkSum += calculateDoubleSumValue(num);
        } else {
            checkSum += num;
        }
        step++;
    }

    return checkSum % 10 == 0;
}

bool luhnCheckCodeSumString()
{
    using namespace std;
    char num;
    int checkSumForEven = 0;
    int checkSumForOdd = 0;
    int step = 0;

    cout << "Enter a number: \n";
    cout << "> ";
    num = cin.get();
    while (num != 10) {
        int number = num - '0';
        checkSumForEven += step % 2 == 0 ? calculateDoubleSumValue(number) : number;
        checkSumForOdd += step % 2 == 1 ? calculateDoubleSumValue(number) : number;
        num = cin.get();
        step++;
    }

    // The last step - it's not a number, it's an end of line
    int checkSum = (step - 1) % 2 ? checkSumForEven : checkSumForOdd;
    cout << "Sum: " << checkSum << "\n";
    return checkSum % 10 == 0;
}


void calculatePositiveAndNegativeNumbers()
{
    int positiveCount = 0;
    int negativeCount = 0;
    int number;

    cout << "Print some number" << "\n";
    for (int i = 0; i < 5; i++) {
        cout << "> ";
    	cin >> number;
        if (number > 0) {
            positiveCount++;
        } else if (number < 0) {
            negativeCount++;
        }
    }

    cout << "Positive numbers count: " << positiveCount << "\n";
    cout << "Negative numbers count: " << negativeCount << "\n";
}