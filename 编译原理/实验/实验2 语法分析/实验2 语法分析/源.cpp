#include<bits/stdc++.h>
using namespace std;

void reshape(string& s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = 'a' + (s[i] - 'A');
    }
}

void print_alpha(string str, ofstream& out) //关键字及标识符
{
    if (str == "begin") {
        cout << "(beginsym,begin)" << endl;
        out << "(beginsym,begin)" << endl;
    }
    else if (str == "call") {
        cout << "(callsym,  call)" << endl;
        out << "(callsym,  call)" << endl;
    }
    else if (str == "const") {
        cout << "(constsym,const)" << endl;
        out << "(constsym,const)" << endl;
    }
    else if (str == "do") {
        cout << "(dosym,      do)" << endl;
        out << "(dosym,      do)" << endl;
    }
    else if (str == "end") {
        cout << "(endsym,    end)" << endl;
        out << "(endsym,    end)" << endl;
    }
    else if (str == "if") {
        cout << "(ifsym,      if)" << endl;
        out << "(ifsym,      if)" << endl;
    }
    else if (str == "odd") {
        cout << "(oddsym,    odd)" << endl;
        out << "(oddsym,    odd)" << endl;
    }
    else if (str == "procedure") {
        cout << "(proceduresym,procedure)" << endl;
        out << "(proceduresym,procedure)" << endl;
    }
    else if (str == "read") {
        cout << "(readsym,  read)" << endl;
        out << "(readsym,  read)" << endl;
    }
    else if (str == "then") {
        cout << "(thensym,  then)" << endl;
        out << "(thensym,  then)" << endl;
    }
    else if (str == "while") {
        cout << "(whilesym,while)" << endl;
        out << "(whilesym,while)" << endl;
    }
    else if (str == "var") {
        cout << "(varsym,    var)" << endl;
        out << "(varsym,    var)" << endl;
    }
    else if (str == "write") {
        cout << "(writesym,write)" << endl;
        out << "(writesym,write)" << endl;
    }
    else {
        cout << "(ident," << setw(7) << str << " )" << endl;
        out << "(ident," << setw(7) << str << " )" << endl;
    }
    return;
}

void print_digit(string str, ofstream& out) { //数字
    cout << "(number," << setw(6) << str << " )" << endl;
    out << "(number," << setw(6) << str << " )" << endl;
    return;
}

void print_others(char str, char str1, ofstream& out) { //其他字符
    if (str == '+') {
        cout << "(plus,       + )" << endl;
        out << "(plus,       + )" << endl;
    }
    else if (str == '-') {
        cout << "(minus,      - )" << endl;
        out << "(minus,      - )" << endl;
    }
    else if (str == '*') {
        cout << "(times,      * )" << endl;
        out << "(times,      * )" << endl;
    }
    else if (str == '/') {
        cout << "(slash,      / )" << endl;
        out << "(slash,      / )" << endl;
    }
    else if (str == '=') {
        cout << "(eql,        = )" << endl;
        out << "(eql,        = )" << endl;
    }
    else if (str == '<') {
        if (str1 == '>') {
            cout << "(neq,       <> )" << endl;
            out << "(neq,       <> )" << endl;
        }
        else if (str1 == '=') {
            cout << "(leq,       <= )" << endl;
            out << "(leq,       <= )" << endl;
        }
        else {
            cout << "(lss,        < )" << endl;
            out << "(lss,        < )" << endl;
        }
    }
    else if (str == '>') {
        if (str1 == '=') {
            cout << "(geq,       >= )" << endl;
            out << "(geq,       >= )" << endl;
        }
        else {
            cout << "(gtr,        > )" << endl;
            out << "(gtr,        > )" << endl;
        }
    }
    else if (str == ':') {
        if (str1 == '=') {
            cout << "(becomes,   := )" << endl;
            out << "(becomes,   := )" << endl;
        }
    }
    else if (str == '(') {
        cout << "(lparen,     ( )" << endl;
        out << "(lparen,     ( )" << endl;
    }
    else if (str == ')') {
        cout << "(rparen,     ) )" << endl;
        out << "(rparen,     ) )" << endl;
    }
    else if (str == ',') {
        cout << "(comma,      , )" << endl;
        out << "(comma,      , )" << endl;
    }
    else if (str == ';') {
        cout << "(semicolon,  ; )" << endl;
        out << "(semicolon,  ; )" << endl;
    }
    else if (str == '.') {
        cout << "(period,     . )" << endl;
        out << "(period,     . )" << endl;
    }
    else {
        cout << "error" << endl;
        out << "error" << endl;
    }
    return;
}

int main()
{
    ifstream infile("in.txt");
    ofstream outfile("out.txt");
    string str, word;
    while (infile >> word) str = str + ' ' + word;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ' || str[i] == '\n') continue;
        //识别常数
        else if (isdigit(str[i]))
        {
            string digit;
            while (isdigit(str[i]))
            {
                digit += str[i];
                i++;
            }
            i--;
            print_digit(digit, outfile);
        }
        //识别基本字或标识符
        else if (isalpha(str[i]))
        {
            string letter;
            while (isalnum(str[i]))
            {
                letter += str[i];
                i++;
            }
            i--;
            reshape(letter);
            print_alpha(letter, outfile);
        }
        //识别运算符
        else
        {
            print_others(str[i], str[i + 1], outfile);
            string cnt;
            cnt += str[i];
            cnt += str[i + 1];
            if (cnt == ">=" || cnt == "<=" || cnt == ":=" || cnt == "<>") i++;
        }
    }
    infile.close();
    outfile.close();
    cout << "\nResult Saved." << endl;
    return 0;
}


