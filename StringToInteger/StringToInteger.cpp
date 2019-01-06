//
// Created by jerrybai on 2018-01-06.
//

/**********************************************************************
 *
 * Description:
 *
 * Implement atoi which converts a string to an integer.
 *
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 *
 * The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned.
 *
 * Note:
 *
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
 *
 *
 * Example 1:
 *
 * Input: "42"
 * Output: 42
 * Example 2:
 *
 * Input: "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus sign.
 *            Then take as many numerical digits as possible, which gets 42.
 * Example 3:
 *
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
 * Example 4:
 *
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a numerical
 *             digit or a +/- sign. Therefore no valid conversion could be performed.
 * Example 5:
 *
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
 *             Thefore INT_MIN (−231) is returned.
 *
 *
***********************************************************************/

// Solution:
//
// Get the required num part of input string, then transfer to integer(assume in range)
//
//
// Algorithm:
//
// 1. Find the first non-whitespace character, if it is not "+/-" or number, input string is invalid, return 0.
// 2. Get the num part of string.
// 3. Remove prefix zero.
// 4. Deal overflow.
// 5. Transfer each character to number.
// 6. Return result.
//
// Time Complexity O(n)
// Space Complexity O(1)


int myAtoi(string str)
{
    size_t startPos = str.find_first_not_of(' ');
    if (startPos == string::npos)
    {
        return 0;
    }

    if (str[startPos] != '+' && str[startPos] != '-' && (str[startPos] < 48 || str[startPos] > 57))
    {
        return 0;
    }

    bool isNegative = false;
    if (str[startPos] == '+' || str[startPos] == '-')
    {
        if (str[startPos] == '-')
        {
            isNegative = true;
        }
        startPos += 1;
    }

    if (startPos >= str.length())
    {
        return 0;
    }

    size_t endPos = str.find_first_not_of("0123456789", startPos);

    int subLen = 0;
    if (endPos != string::npos)
    {
        subLen = endPos - startPos;
    }
    else
    {
        subLen = str.length() - startPos;
    }

    string numStr = str.substr(startPos, subLen);
    if (numStr.length() > 10)
    {
        if (isNegative)
        {
            return INT_MIN;
        }
        else
        {
            return INT_MAX;
        }
    }

    long ans = 0;
    for (int i = 0; i < numStr.length(); i++)
    {
        ans = ans * 10 + (numStr[i] - 48);
    }

    if (isNegative)
    {
        ans = -ans;
    }

    if (ans > INT_MAX)
    {
        return INT_MAX;
    }
    else if (ans < INT_MIN)
    {
        return INT_MIN;
    }

    return ans;
}
