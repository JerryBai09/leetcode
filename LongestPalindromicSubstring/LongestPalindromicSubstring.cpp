//
// Created by jerrybai on 2018-12-16.
//

/**********************************************************************
 *
 * Description:
 *
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 *
 * Example 1:
 *
 * IInput: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 * Example 2:
 *
 * Input: "cbbd"
 * Output: "bb"
 *
 *
***********************************************************************/

// Solution:
//
// Using DP for all palindromic substring
//
// The base of palindromic string is:
// 1. If s[i][j] is palindromic, there must be s[i] = s[j] and s[i+1][j-1] is palindromic, where s[i][j] marked the substring s[i:j]
// 2. s[i][i] is palindromic.
// 3. s[i][i+1] is palindromic only if s[i] = s[i+1]
// 4. Given 2 and 3, if j - i <= 2, only need check if s[i] = s[j]
//
// Algorithm:
//
// 1.Initialize a two dimension array to mark if s[i][j] is palindromic.
// 2.If s[i] = s[j] && inner string is palindromic, s[i][j] is palindromic.
// 3.If j - i < 2, inner string is less or equal to 1, it is palindromic
// 4.Return the longest palindromic substring.
//
// Time Complexity O(n^2)
// Space Complexity O(n^2).

// Attention:
// 1. The two dimension array must be initialized first.
// 2. Two for loops must be as demonstrated in the code, as the result rely on the former palindromic string
//


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
        {
            return s;
        }

        int len = s.size();
        bool isPalindrome[len][len] = {false};
        int start = 0;
        int end = 0;

        //DP for each substring
        for (int j = 1; j < len; j++)
            for (int i = 0; i < j; i++)
            {
                bool innerPalindrome = isPalindrome[i+1][j-1] || j - i <= 2; //less or euqal three elements
                if (s[i] == s[j] && innerPalindrome)
                {
                    isPalindrome[i][j] = true;

                    if (j - i > end - start)
                    {
                        end = j;
                        start = i;
                    }
                }
            }

        return s.substr(start, end - start + 1);
    }
};
