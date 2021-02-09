#include <stdio.h>

enum {
    NUMBER,
    PLUS,
    MINUS,
    MUL,
    SUB,
    LEFTPAR,
    RIGHTPAR
} tokenClass;
char* tokenVal;
size_t tokenVal_len;

void getNext() {
    tokenVal += tokenVal_len;
    if (tokenVal[0] == '+') {
        tokenClass = PLUS;
        tokenVal_len = 1;
    } else if (tokenVal[0] == '-') {
        tokenClass = MINUS;
        tokenVal_len = 1;
    } else if (tokenVal[0] == '*') {
        tokenClass = MUL;
        tokenVal_len = 1;
    } else if (tokenVal[0] == '/') {
        tokenClass = SUB;
        tokenVal_len = 1;
    } else if (tokenVal[0] == '(') {
        tokenClass = LEFTPAR;
        tokenVal_len = 1;
    } else if (tokenVal[0] == ')') {
        tokenClass = RIGHTPAR;
        tokenVal_len = 1;
    } else if (tokenVal[0] >= '0' && tokenVal[0] <= '9') {
        tokenClass = NUMBER;
    }
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
