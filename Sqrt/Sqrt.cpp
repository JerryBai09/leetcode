//
// Created by jerrybai on 2018-12-22.
//

/**********************************************************************
 *
 * Description:
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
 *
 * Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
 *
 *
 * Example 1:
 *
 * Input: 4
 * Output: 2
 * Explanation: The answer is "abc", with the length of 3.
 *
 * Example 2:
 *
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since
 *           the decimal part is truncated, 2 is returned.
 *
 *
***********************************************************************/

// Solution:
//
// Bounded binary search:
//
// Search the whole int array in range [1, x) to find the sqrt of x, except x is 0 or 1
// Assume the answer is m, then m^2 <= x <= (m+1)^2. So x should be upper bound of m^2
//
// Algorithm:
//
// 1.If x is 0 or 1, return x.
// 2.Using binary search in range [1, x) to find out the middle m, if m^2 == x.
// 3.If x > m^2, then search range should be [m+1, r). m may be the target bound value.
// 4.If x < m^2, then search range should be [l, m).
// 5.return if sqrt exactly find or reach search bound
//
// Time Complexity O(logn)
// Space Complexity O(1).
//

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }
        int l = 1, r = x;
        int ans;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (m == x / m) {
                return m;
            } else if (m < x / m) {
                l = m + 1;
                ans = m;
            } else {
                r = m;
            }
        }
        return ans;
    }
};
