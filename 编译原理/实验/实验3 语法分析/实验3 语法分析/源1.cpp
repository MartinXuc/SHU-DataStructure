#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include <cstdio>
using namespace std;
ifstream fin("in.txt");
ofstream fout("out.txt");

typedef pair<string, string> Token;

// ����ȫ�ֱ��� token_list ���洢����Ķ�Ԫʽ����
vector<Token> token_list;
int current_pos = 0;

// ��������
void parse_expression();
void parse_term();
void parse_factor();

bool is_add_operator(const Token& token) {
    return token.first == "plus" || token.first == "minus";
}

bool is_mul_operator(const Token& token) {
    return token.first == "times" || token.first == "divide";
}

bool is_identifier(const Token& token) {
    return token.first == "ident";
}

bool is_unsigned_integer(const Token& token) {
    return token.first == "number";
}

bool is_lparen(const Token& token) {
    return token.first == "lparen";
}

bool is_rparen(const Token& token) {
    return token.first == "rparen";
}

void parse_expression() {
    if (current_pos < token_list.size()) {
        if (token_list[current_pos].first == "plus" || token_list[current_pos].first == "minus") {
            ++current_pos;
        }
        parse_term();
        while (current_pos < token_list.size() && is_add_operator(token_list[current_pos])) {
            ++current_pos;
            parse_term();
        }
    }
}


void parse_term() {
    parse_factor();
    while (current_pos < token_list.size() && is_mul_operator(token_list[current_pos])) {
        ++current_pos;
        parse_factor();
    }
}

void parse_factor() {
    if (current_pos < token_list.size()) {
        if (is_identifier(token_list[current_pos]) || is_unsigned_integer(token_list[current_pos])) {
            ++current_pos;
        }
        else if (is_lparen(token_list[current_pos])) {
            ++current_pos;
            parse_expression();
            if (current_pos < token_list.size() && is_rparen(token_list[current_pos])) {
                ++current_pos;
            }
            else {
                fout << "����ȱ�������� ')' " << endl;
                exit(1);
            }
        }
        else {
            fout << "������Ч������ " << endl;
            exit(1);
        }
    }
    else {
        fout << "��������Ķ�Ԫʽ���в�����" << endl;
        exit(1);
    }
}

int main() {
    string s1, s2, s3;
    while(!fin.eof())
    {
        fin >> s1 >> s2 >> s3;
        s1.erase(0, 1);
        s1.erase(s1.size() - 1, 1);
        Token t = make_pair(s1, s2);
        token_list.push_back(t);
    }
    try {
        if (token_list.empty()) {
            fout << "��������Ķ�Ԫʽ����Ϊ��" << endl;
            return 0;
        }
        parse_expression();

        if (current_pos == token_list.size()) {
            fout << "��ȷ�ı��ʽ" << endl;
        }
        else {
            fout << "�����޷�����������" << endl;
        }
    }
    catch (const exception& e) {
        fout << "����" << e.what() << endl;
    }

    fin.close();
    fout.close();

    return 0;
}