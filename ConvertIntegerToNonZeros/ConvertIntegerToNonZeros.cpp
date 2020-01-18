//
// Created by Jerry Bai on 2020-01-12.
//


/**********************************************************************
* Given an integer n. No-Zero integer is a positive integer which doesn't contain any 0 in its decimal representation.
* 
* Return a list of two integers [A, B] where:
* 
* A and B are No-Zero integers.
* A + B = n
* It's guarateed that there is at least one valid solution. If there are many valid solutions you can return any of them.
* 
*  
* 
* Example 1:
* 
* Input: n = 2
* Output: [1,1]
* Explanation: A = 1, B = 1. A + B = n and both A and B don't contain any 0 in their decimal representation.
* Example 2:
* 
* Input: n = 11
* Output: [2,9]
* Example 3:
* 
* Input: n = 10000
* Output: [1,9999]
* Example 4:
* 
* Input: n = 69
* Output: [1,68]
* Example 5:
* 
* Input: n = 1010
* Output: [11,999]
*  
* 
* Constraints:
* 
* 2 <= n <= 10^4
* 
* 来源：力扣（LeetCode）
* 链接：https://leetcode-cn.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers
*********************************************************************/


// Solution:
// Using brute-force to get two required numbers.
// For each pair of numbers, transfer to string to decide if 0 digit exists in the num
//
// Snippet:
// Int to string: string str = to_string(int i)
// String to int: int num = atoi(string str)
// String find: if (str.find(target) != string::npos) target exists
//
// Additional comments:
// Checking for remain of most significant digit will fail in situation such as input number is 69



#include <vector>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;


bool isNonZeroInteger(int num) {
    string num_str = to_string(num);
    if (num_str.find('0') != string::npos) {
        return false;
    }
    return true;
}

vector<int> getNoZeroIntegers(int n) {
    if (n <= 1) return {};

    for (int i = 1; i <= n/2; i++) {
        if (isNonZeroInteger(i) && isNonZeroInteger(n - i)) {
            return {i, n - i};
        }
    }

    return {};
}


int main() {
    int num;
    vector<int> res;
    while (cin >> num) {
        res = getNoZeroIntegers(num);
        cout << "Decompose res ";
        for (auto i : res) {
            cout << i << " ";
        }
        cout << endl;
    }
}

