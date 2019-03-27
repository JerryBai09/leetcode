//
// Created by jerrybai on 2019-3-27.
//

/**********************************************************************
 *
 * Description:
 *
 * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 *
 * Note:
 *
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters like . or *.
 *
 *
 * Example 1:
 *
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 * Example 2:
 *
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
 *
 * Example 3:
 *
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 *
 * Example 4:
 *
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
 *
 * Example 5:
 *
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 *
***********************************************************************/

// Solution:
//
// Using DP for regular match of two expressions
//
// Let dp[i][j] denote the matching result of expression s[0, i) and p[0, j). The base of regular matching is:
// 1. If p[j - 1] is '.', it match any s[i - 1]
// 2. If p[j - 1] is not '*'(a-z or '.'), dp[i][j] will be true only s[i - 1] match p[j -1] and dp[i - 1][j -1] is true
// 3. If p[j - 1] is '*', there are two cases:
// 4. First, if '*' means the repeat of 0 times, dp[i][j] will be true only if dp[i][j - 2] is true
// 5. Second, if '*' means the repeat of 1 or more times, dp[i][j] will be true only if dp[i - 1][j] is true and s[i - 1] match p[j - 2]
// 6. To empty case, set dp[0][0] to true and handle empty situations in both above cases
//
// Algorithm:
//
// 1.Initialize a two dimension array to mark if s[0, i) and p[0, j) match.
// 2.Calculate dp according the base of regular matching
// 3.Handle empty case is both situations
// 4.Return the result of dp[m][n].
//
// Time Complexity O(m * n)
// Space Complexity O(m * n).

// Attention:
// 1. The two dimension array must be initialized to (m + 1) * (n + 1) to handle the empty case.
//


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        //dp[i][j] be true if s[0, j) and p[0, j) matched
        vector<bool, vector<bool>> dp(m + 1, vector<bool>(n+1, false));
        dp[0][0] = true;

        //if pattern is empty and source is not empty, all results are false
        for (int i = 0; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
                else
                {
                    dp[i][j] = i && dp[i-1][j-1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }

        return dp[m][n];
    }
};
