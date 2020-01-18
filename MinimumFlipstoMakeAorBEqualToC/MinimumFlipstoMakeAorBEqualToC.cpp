//
// Created by Jerry Bai on 2020-01-19.
//


/**********************************************************************
* Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
* Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.
* 
* 
* 
* Example 1:
* 
* 
* 
* Input: a = 2, b = 6, c = 5
* Output: 3
* Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
* Example 2:
* 
* Input: a = 4, b = 2, c = 7
* Output: 1
* Example 3:
* 
* Input: a = 1, b = 2, c = 3
* Output: 0
* 
* 
* Constraints:
* 
* 1 <= a <= 10^9
* 1 <= b <= 10^9
* 1 <= c <= 10^9
*********************************************************************/

// Solution:
// First: find out all bits that need flips by xor a|b and c
// Second: For each needed flip bit, check the origin bit value
// If the origin bit is 0, this bit of a and b must be 0. Just change the bit of one of these two number to 1. So flips needed would be 1.
// If the origin bit is 1, there must be at least one bit of a and b originally be 1. To make result bit to 0, we must ensure that this bit of both a and b to be 0
// So we need to check both bits of a and b, and flip them if needed. Each flip would add one count.


int mask(int i) {
    return 1 << i;
}

int minFlips(int a, int b, int c) {
    int count = 0;
    int origin = a | b;
    int diff = origin ^ c;
    int i = 0;
    while(mask(i) <= diff) {
        if (diff & mask(i)) {
            if (!(origin & mask(i))) {
                count += 1;
            }
            else {
                if (a & mask(i)) count += 1;
                if (b & mask(i)) count += 1;
            }
        }
        i++;
    }
    return count;
}
