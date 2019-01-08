//
// Created by jerrybai on 2019-01-08.
//

/**********************************************************************
 *
 * Description:
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 *
 * Example 1:
 *
 * Input: 121
 * Output: true
 * Example 2:
 *
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 * Example 3:
 *
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 *
 *
***********************************************************************/

// Solution:
//
// Reverse the input integer and compare if the two numbers are same.
// However, this reverse may lead to overflow.
// So just reverse the second half part of input number, and decide whether the two parts integer are same.
//
//
// Algorithm:
//
// 1.If the input integer is negative or last digit is zero(the number is non-zero), this integer is not palindrome.
// 2.Build up the two parts of input integer, the end condition is that the first part is less or equal than the reverse part.
// 3.If the length of integer is odd, the reverse part has an additional digit than first part. So first treating reverse/10 to ignore the additional digit.
// 4.If the length of integer is even, the two parts are same length.
// 5.Compare the two newly build numbers, return true if they are same.
//
// Time Complexity O(logn)
// Space Complexity O(1).
//

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || 0 == x % 10 && x != 0) //last digit is zero, not palindrome
        {
            return false;
        }

        int reverse = 0;
        while (x > reverse)
        {
            reverse = reverse * 10 + x % 10;
            x = x / 10;
        }

        return x == reverse || x == reverse/10;
    }
};
