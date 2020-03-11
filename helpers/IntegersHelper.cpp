int unsignedPow(int base, int pow)
{
    int result = 1;
    for (int i = 1; i <= pow; i++) {
    	result *= base;
    }
    return result;
}

int stringToInteger(std::string code)
{
    int codeLength = code.length();
    if (codeLength == 0) {
        return 0;
    }
    int result = code[0] - '0';
    if (codeLength == 1) {
        return result;
    }
    int number = code[1] - '0';
    for (int i = 2; i < codeLength; i++) {
        result = result * 10 + number;
        number = code[i] - '0';
    }
    return result * 10 + number;
}