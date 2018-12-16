//
// Created by jerrybai on 2018-12-16.
//

/**********************************************************************
 *
 * Description:
 *
 * Given a string, find the length of the longest substring without repeating characters.
 *
 *
 * Example 1:
 *
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 * Example 2:
 *
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 * Example 3:
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 *            Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
***********************************************************************/

// Solution:
//
// Slide window solution:
//
// A slide window which contains the current longest unique substring slide across the whole string.
// If current character repeats the slide window contents, update the left and right index to keep the window attribute.
//
// Algorithm:
//
// 1.Move the right index to the next character of string.
// 2.Use a hash map to keep track of the slide window. If current character already exists in the slide map,
//   update left index of slide window to the next of repeat character index. Repeat index should not be out of left boundary.
// 3.Update the maxLen if the length of current slide window is greater than maxLen.
// 4.Insert the current character pair to the slide map, update to new index if character already exists.
// 5.return max length.
//
// Time Complexity O(n)
// Space Complexity O(min(m, n)). We need O(k) space for the sliding window, where k is the size of the Map.
// The size of the Map is upper bounded by the size of the string n and the size of the charset/alphabet m.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int maxLen = 0;
        unordered_map<char, int> slideMap; //Contains the slide window of input string
        //Slide the right boundry of string, check if left should be updated
        for (int left = 0, right = 0; right < len; right++)
        {
            //If current character already exists in the map[left, right], update left
            if (slideMap.find(s[right]) != slideMap.end())
            {
                left = max(left, slideMap[s[right]] + 1);
            }
            maxLen = max(maxLen, right - left + 1);
            //Should not use insert here, as if Key exists, insert do nothing
            //slideMap.insert(unordered_map<char, int>::value_type(s[right], right));
            slideMap[s[right]] = right;
        }
        return maxLen;
    }
};
