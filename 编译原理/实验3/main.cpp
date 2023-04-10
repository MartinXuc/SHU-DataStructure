#include <iostream>
void expression();
void term();
void factor();
void initTokenList();
void getNextToken();
int main() {
    printf("Please input an expression: ");
    initTokenList();
    getNextToken();
    expression();
    if (token.type != END) {
        error("Invalid expression");
    } else {
        printf("Syntax analysis succeeded\n");
    }
    return 0;
}


void expression() {
    if (token.type == PLUS || token.type == MINUS) {
        getNextToken();
    }
    term();
    while (token.type == PLUS || token.type == MINUS) {
        getNextToken();
        term();
    }
}
void term() {
    factor();
    while (token.type == TIMES || token.type == SLASH) {
        getNextToken();
        factor();
    }
}
void factor() {
    if (token.type == IDENTIFIER) {
        getNextToken();
    } else if (token.type == NUMBER) {
        getNextToken();
    } else if (token.type == LPAREN) {
        getNextToken();
        expression();
        if (token.type == RPAREN) {
            getNextToken();
        } else {
            error("Missing right parenthesis");
        }
    } else {
        error("Invalid factor");
    }
}
void initTokenList() {
    FILE *fp = fopen("in.txt", "r");
    char input[MAX_INPUT_LENGTH];
    fgets(input, MAX_INPUT_LENGTH, fp);
    int len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    int pos = 0;
    while (pos < len) {
        Token token = getNextTokenFromString(input, &pos);
        if (token.type != UNKNOWN) {
            tokenList[tokenCount++] = token;
        }
    }
    tokenList[tokenCount++] = (Token) {END, ""}; // 加入 END Token
    fclose(fp);
}
void getNextToken()
{
    currentToken = tokenList[currentTokenIndex++];
}