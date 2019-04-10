//
// Created by jerrybai on 2019-04-10.
//

/**********************************************************************
 *
 * Description:
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 *
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 *
 * I can be placed before V (5) and X (10) to make 4 and 9.
 * X can be placed before L (50) and C (100) to make 40 and 90.
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
 *
 *
 * Example 1:
 *
 * Input: "III"
 * Output: 3
 * Example 2:
 *
 * Input: "IV"
 * Output: 4
 * Example 3:
 *
 * Input: "IX"
 * Output: 9
 * Example 4:
 *
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * Example 5:
 *
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *
***********************************************************************/

// Solution:
//
// Add each symbol in roman to get the integer value.
// Pay attention to cases that symbol indicate integer less than the next one, which should be a combination,
// and subtract the two integer
//
// Time Complexity O(m)
// Space Complexity O(k), k is the length of roman map.


class Solution {
public:
    int romanToInt(string s) {
        std::map<char, int> romanMap;
        romanMap.insert(std::pair<char, int>('M', 1000));
        romanMap.insert(std::pair<char, int>('D', 500));
        romanMap.insert(std::pair<char, int>('C', 100));
        romanMap.insert(std::pair<char, int>('L', 50));
        romanMap.insert(std::pair<char, int>('X', 10));
        romanMap.insert(std::pair<char, int>('V', 5));
        romanMap.insert(std::pair<char, int>('I', 1));

        int value = 0;
        std::string::size_type idx = 0;
        std::string::size_type strLen = s.size();
        while (idx < strLen)
        {
            if (idx + 1 < strLen && romanMap.at(s[idx]) < romanMap.at(s[idx + 1]))
            {
                value += romanMap.at(s[idx + 1]) - romanMap.at(s[idx]);
                idx++;
            }
            else
            {
                value += romanMap.at(s[idx]);
            }

            idx++;
        }

        return value;
    }
};
