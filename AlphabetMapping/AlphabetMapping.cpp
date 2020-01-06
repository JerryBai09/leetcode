//
// Created by JerryBai on 2020-01-07.
//

#include <string>
#include <iostream>

using namespace std;

string freqAlphabets(string s) {
    if (s.size() == 0) return "";

    int len = s.size();
    string str;
    string ans;
    int i = 0;
    while (i < len) {
        if (i > len - 3) {
            str = s.substr(i);
            for (auto ch : str) {
                ans += ch - '1' + 'a';
            }
            return ans;
        } else {
            str = s.substr(i, 3);
            if (str[2] == '#') {
                ans += atoi(str.substr(0, 2).c_str()) + 'a' - 1;
                i += 3;
            } else {
                ans += str[0] - '1' + 'a';
                i += 1;
            }
        }
    }

    return ans;
}

int main() {
    string str1 = "10#11#12";
    cout << freqAlphabets(str1) << endl;
    string str2 = "1326#";
    cout << freqAlphabets(str2) << endl;
    string str3 = "25#";
    cout << freqAlphabets(str3) << endl;
    string str4 = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#";
    cout << freqAlphabets(str4) << endl;


    return 0;
}