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
    int result = 0;
    for (int i = 0; i < codeLength; i++) {
    	result = result * 10 + (code[i] - '0');
    }
    return result;
}