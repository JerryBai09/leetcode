//
// Created by jerrybai on 2019-01-02
//

/**********************************************************************
 *
 * Description:
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 * Input: 123
 * Output: 321
 *
 * Example 2:
 *
 * Input: -123
 * Output: -321
 *
 * Example 3:
 *
 * Input: 120
 * Output: 21
 *
 *
***********************************************************************/

// Solution:
//
//
// Using mode to get each digits from LSB to MSB. Build up the reverse in the opposite way which seems like handling by deque.
//
// Algorithm:
//
// 1. Get each digit(reminder) and append to the return value by ans = ans * 10 + reminder
// 2. Before build up ans, check if result would overflow. Condition is that ans > INT_MAX/10 or ans == INT_MAX/10 and reminder > 7
// 3. Condition for negative is alike.
// 4. Overflow condition: INT_MAX is 2,147,483,647, and INT_MAX/10 is 214,748,364. So if reminder is great than 7, ans would overflow
//                        INT_MIN is 2,147,483,648, so if reminder is less than -8, ans would overflow
// 5. Return result
//
// Time Complexity O(log(n))
// Space Complexity O(1)


class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0)
        {
            int reminder = x % 10;
            x = x / 10;
            // overflow check
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && reminder > 7))
            {
                return 0;
            }
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && reminder < -8))
            {
                return 0;
            }
            ans = ans * 10 + reminder;
        }

        return ans;
    }
};
