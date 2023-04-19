//#include<bits/stdc++.h>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;

void reshape(string& s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = 'a' + (s[i] - 'A');
    }
}

string basic[] = {
        "begin", "call", "const", "do","end",
        "if","odd","procedure","read",
        "then", "var", "while", "write"
};

int main() {
    ofstream outfile("out.txt"); // 创建一个输出文件流
    ifstream infile("in.txt"); // 创建一个输入文件流
    string str, s1, now = "";
    map<string, int>ans;
    vector<string>show;
    while (getline(infile, str)) {
        stringstream ss(str);
        while (ss >> s1) {
            reshape(s1);
            int j = 0;   //是否查询到一个新的以字母开头的字符串
            int len = s1.size();
            for (int i = 0; i < len; i++) {
                if (s1[i] >= 'a' && s1[i] <= 'z') {
                    if (!j) {
                        j = 1;
                        now = "";
                        now += s1[i];
                    }
                    else
                        now += s1[i];
                }
                else if (s1[i] >= '0' && s1[i] <= '9') {
                    if (j) {
                        now += s1[i];
                    }
                }
                else {   //碰到了标点符号等
                    if (j) {
                        int ok = 0;  //不在基本字中
                        for (int jj = 0; jj <= 12; jj++) {
                            if (now == basic[jj]) {
                                ok = 1;
                                break;
                            }
                        }
                        if (!ok) {
                            ans[now]++;
                            if (ans[now] == 1)
                                show.push_back(now);
                        }
                        j = 0;
                    }
                }
            }
            if (j) {
                int ok = 0;  //不在基本字中
                for (int jj = 0; jj <= 12; jj++) {
                    if (now == basic[jj]) {
                        ok = 1;
                        break;
                    }
                }
                if (!ok) {
                    ans[now]++;
                    if (ans[now] == 1)
                        show.push_back(now);
                }
                j = 0;
            }
        }
    }
    for (auto i : show) {
        cout << "(" << i << ": " << ans[i] << ")" << endl;
        outfile << "(" << i << ": " << ans[i] << ")" << endl;
    }
    infile.close(); // 关闭文件
    outfile.close();
    return 0;
}
