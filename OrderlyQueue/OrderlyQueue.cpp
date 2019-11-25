//
// Created by 白俊彦 on 2019-11-22.
//

/**********************************************************************
* A string S of lowercase letters is given.  Then, we may make any number of moves.
* 
* In each move, we choose one of the first K letters (starting from the left), remove it, and place it at the end of the string.
* 
* Return the lexicographically smallest string we could have after any number of moves.
* 
*  
* 
* Example 1:
* 
* Input: S = "cba", K = 1
* Output: "acb"
* Explanation:
* In the first move, we move the 1st character ("c") to the end, obtaining the string "bac".
* In the second move, we move the 1st character ("b") to the end, obtaining the final result "acb".
* Example 2:
* 
* Input: S = "baaca", K = 3
* Output: "aaabc"
* Explanation:
* In the first move, we move the 1st character ("b") to the end, obtaining the string "aacab".
* In the second move, we move the 3rd character ("c") to the end, obtaining the final result "aaabc".
*  
* 
* Note:
* 
* 1 <= K <= S.length <= 1000
* S consists of lowercase letters only.
* 
* 来源：力扣（LeetCode）
* 链接：https://leetcode-cn.com/problems/orderly-queue
* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*********************************************************************/


#include <string>
#include <iostream>

using namespace std;

string orderlyQueue(string S, int K) {
    // Condition: S.length() >= 1
    // if (S.size() == 0) return "";

    string ans = S;
    if (1 == K) {
        // The cycle rotate of input string
        for (int i = 0; i < S.length(); i++) {
            string temp = S.substr(i) + S.substr(0, i);
            if (temp < ans) ans = temp;
        }
    } else {
        // The permutation of input string
        sort(ans.begin(), ans.end());
    }

    return ans;
}


// Test section
int main() {
    string s1 = "cba";
    int k1 = 1;
    string ret1 = orderlyQueue(s1, k1);
    cout << "queued s1 is " << ret1 << endl;

    string s2 = "baaca";
    int k2 = 3;
    string ret2 = orderlyQueue(s2, k2);
    cout << "queued s2 is " << ret2 << endl;

    return 0;
}