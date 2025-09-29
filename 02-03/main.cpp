#include <iostream>
#include <map>

enum symbol {
    UPPER_CASE_SYMBOL = 0,
    LOWER_CASE_SYMBOL = 1,
    DIGIT_SYMBOL = 2,
    PUNCTUATION_SYMBOL = 3,
    OTHER_SYMBOL = 4
};

symbol getSymbolType(char ch) {
    switch (ch) {
        case 'A' ... 'Z': return UPPER_CASE_SYMBOL;
        case 'a' ... 'z': return LOWER_CASE_SYMBOL;
        case '0' ... '9': return DIGIT_SYMBOL;
        case '.':
        case ',':
        case '!': [[fallthrough]];
        case '?':
        case ':':
        case ';':
        case '(':
        case ')':
        case '-':
        case '\"': return PUNCTUATION_SYMBOL;
        default: return OTHER_SYMBOL;
    }
}

std::map<symbol, const char*> CLASS_NAMES = {
    {UPPER_CASE_SYMBOL, "upper case symbol"},
    {LOWER_CASE_SYMBOL, "lower case symbol"},
    {DIGIT_SYMBOL, "digit symbol"},
    {PUNCTUATION_SYMBOL, "punctuation symbol"},
    {OTHER_SYMBOL, "other symbol"}
};

int main() {
    char ch = '\0';
    std::cin >> ch;
    std::cout << ch << " is " << CLASS_NAMES[getSymbolType(ch)] << std::endl;
}