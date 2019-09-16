//
// Created by jerrybai on 2019-09-16.
//

/**********************************************************************
 *
 * Description:
 *
 * Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 *
 * Below is one possible representation of s1 = "great":
 *
 *     great
 *    /    \
 *   gr    eat
 *  / \    /  \
 * g   r  e   at
 *           / \
 *         a   t
 *
 * To scramble the string, we may choose any non-leaf node and swap its two children.
 *
 * For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
 *
 *   rgeat
 *   /    \
 *  rg    eat
 * / \    /  \
 *r   g  e   at
 *           / \
 *          a   t
 *
 * We say that "rgeat" is a scrambled string of "great".
 *
 * Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
 *
 *
 *    rgtae
 *   /    \
 *  rg    tae
 * / \    /  \
 * r   g  ta  e
 *       / \
 *      t   a
 * We say that "rgtae" is a scrambled string of "great".
 *
 * Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 *
 * Example 1:
 *
 * Input: s1 = "great", s2 = "rgeat"
 * Output: true
 * Example 2:
 *
 * Input: s1 = "abcde", s2 = "caebd"
 * Output: false
 *
 *
 *
***********************************************************************/

// Solution:
//
// As described above, scramble string is some transformations that exchange some non-leaf nodes and re-construct a new string
// The string and transform is described in tree mode and no other apparent rules can be found, so we try DFS + BT to solve this problem
//
// To DFS, recursion should be used. So following aspects are considered:
// 1. End condition1: the swap ends in single character or any same substrings of two input strings, so the end condition of recursion should be equal of two input string
// 2. End condition2: If two input string is not anagrams, it is impossible to be scramble strings
//
// 3. Recursion action: for each input strings, divide input string in any possible position, and check if the four substrings match scramble strings condition: (left1 <-scramble-> left2 && right1 <-scramble-> right2) || (left1 <-scramble-> right2 && left2 <-scramble-> right1)
//
// 4. Otherwise return false
// If thre is no End conditon2(cut cases), Space Complexity O(n!)
//

class Solution {
public:
    bool isScramble(string s1, string s2) {
      // End condition1
      if (s1 == s2) return true;

      //End conditon2
      string tmp1 = s1;
      string tmp2 = s2;
      sort(tmp1.begin(), tmp1.end());
      sort(tmp2.begin(), tmp2.end());
      if (tmp1 != tmp2) return false;

      for (int i = 1; i < s1.size(); i++) {
        if (  (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
            ||(isScramble(s1.substr(0, i), s2.substr(s2.size()-i)) && isScramble(s1.substr(i), s2.substr(0, s2.size() - i)))
          )
          return true;
      }

      return false;
    }
};
