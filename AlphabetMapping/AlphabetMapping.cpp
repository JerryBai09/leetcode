//
// Created by JerryBai on 2020-01-07.
//

/**********************************************************************
* Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:
* 
* Characters ('a' to 'i') are represented by ('1' to '9') respectively.
* Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
* Return the string formed after mapping.
* 
* It's guaranteed that a unique mapping will always exist.
* 
*  
* 
* Example 1:
* 
* Input: s = "10#11#12"
* Output: "jkab"
* Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
* Example 2:
* 
* Input: s = "1326#"
* Output: "acz"
* Example 3:
* 
* Input: s = "25#"
* Output: "y"
* Example 4:
* 
* Input: s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
* Output: "abcdefghijklmnopqrstuvwxyz"
*  
* 
* Constraints:
* 
* 1 <= s.length <= 1000
* s[i] only contains digits letters ('0'-'9') and '#' letter.
* s will be valid string such that mapping is always possible.
* 
* 
* 来源：力扣（LeetCode）
* 链接：https://leetcode-cn.com/problems/decrypt-string-from-alphabet-to-integer-mapping
* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*********************************************************************/


// Solution:
// Greedy Algorithm:
// First try to get 3 characters of input string
// If failed, the remaining alphabet could only be mapped as 'a' - 'i' respectively
// If success, try to map as a combination of '#' to 'j'-'z'
// If no '#' in the third place of characters, mapping the first character to 'a'-'i'
// Start from the remaining position, repeat the above processes
// Trick: using remaining index to control the processed string is simpler than fetch a target substring


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