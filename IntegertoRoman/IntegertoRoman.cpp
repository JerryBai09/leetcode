//
// Created by jerrybai on 2019-04-03.
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
 *
 * For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 *
 * I can be placed before V (5) and X (10) to make 4 and 9.
 * X can be placed before L (50) and C (100) to make 40 and 90.
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
 *
 *
 * Example 1:
 *
 * Input: 3
 * Output: "III"
 * Example 2:
 *
 * Input: 4
 * Output: "IV"
 * Example 3:
 *
 * Input: 9
 * Output: "IX"
 * Example 4:
 *
 * Input: 58
 * Output: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.
 * Example 5:
 *
 * Input: 1994
 * Output: "MCMXCIV"
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *
***********************************************************************/

// Solution:
//
// Calculate the result of each module by roman characters, from the highest to lowest.
// For some combination of subtraction like 4 and 9, deal special cases.
//
// Algorithm:
//
// 1.Get each digit by divide and module.
// 2.For divide result, append the result times of roman characters to return string.
// 3.For special cases like 4 and 9, as following:
// 4.Cases like 4, 40 and 400, just subtract according number, append the combination symbols to result string, and deal the next module
// As the next module's digit is less than current, only one should be passed(like 50 10 5, pass one is 10, pass two is 5)
// 5.Cases like 9, 90 and 900, just get the combination and move two modules before current number
// 6.Repeat until the reminder is 0.
//

// Time Complexity O(m), m is size of roman characters
// Space Complexity O(1)
//


string intToRoman(int num) {
    vector<char> roman = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    vector<int> mod = {1, 5, 10, 50, 100, 500, 1000};
    string symbol;
    int index = roman.size() - 1;
    int result = 0;
    while (num > 0) {
        result = num / mod[index];
        num = num % mod[index];
        symbol.append(result, roman[index]);

        int gap = index % 2 ? 1 : 2;

        // For 900 and 90 and 9 || 400 and 40 and 4
        if (index - gap >= 0 && num >= mod[index] - mod[index - gap]) {
            symbol.push_back(roman[index - gap]);
            symbol.push_back(roman[index]);
            num -= (mod[index] - mod[index - gap]);
            // if 9 || 90 || 900, skip according 5 || 50 || 500
            index -= (gap - 1);
        }
        index--;
    }

    return symbol;
}
