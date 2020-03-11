#include <iostream>
#include <vector>
using namespace std;

class Numeral
{
    private:
        int value;
        vector<int> numbersDesc;
        vector<int> numbersAsc;

    public:
        Numeral(int number)
        {
            value = number;
        }


        int getValue()
        {
            return value;
        }

        int size()
        {
            getNumbers(true);
            return numbersDesc.size();
        }

        vector<int> getNumbers()
        {
            return getNumbers(false);
        }

        vector<int> getNumbers(bool desc)
        {
            if (numbersDesc.size() == 0) {
                int left = value;
                while (left >= 10) {
                    numbersDesc.push_back(left % 10);
                    left /= 10;
                }
                numbersDesc.push_back(left);
            }

            if (desc == false && numbersAsc.size() == 0) {
                for (int i = numbersDesc.size() - 1; i >= 0; i--) {
                    numbersAsc.push_back(numbersDesc[i]);
                }
            }

            return desc == true ? numbersDesc : numbersAsc;
        }

        int getNumbersSum()
        {
            int sum = 0;
            for (int number : getNumbers(false)) {
                sum += number;
            }
            return sum;
        }
};