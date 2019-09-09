//
// Created by jerrybai on 2019-09-08.
//

/**********************************************************************
 *
 * Description:
 *
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 *
 *
 * Write a function to determine if a number is strobogrammatic. The number is represented as a string.
 *
 * For example, the numbers “69”, “88”, and “818” are all strobogrammatic.
 *
 *
 * Hide Tags Hash Table Math 
 * Hide Similar Problems (M) Strobogrammatic Number II (H) Strobogrammatic Number III.
 *
 *
***********************************************************************/

// Solution:
//
// Strobogrammatic number pairs exists only in the following cases:
// 6 -> 9
// 9 -> 6
// 0 -> 0
// 1 -> 1
// 8 -> 8
//
// Check each character of the input string and if there exists some pairs not match the map condition, return false
// Otherwise return true
// Space Complexity O(n)

class Solution {
public:
    bool isStrobogrammatic(string num) {
      if (0 == num.size()) {
        return false;
      }

      std::unordered_map<char, char> stroMap;
      stroMap['6'] = '9';
      stroMap['9'] = '6';
      stroMap['0'] = '0';
      stroMap['1'] = '1';
      stroMap['8'] = '8';

      int i = 0, j = num.size() - 1;
      while (i <= j) { //i == j must check to ensure the odd situation where only 0 1 8 could exist in the middle position
        if (stroMap.find(num[i]) == stroMap.end()) {
          return false;
        }

        if (stroMap[num[i]] != num[j]) {
          return false;
        }
        i++;
        j--;
      }

      return true;
    }
};


// This part is for unit tests
/*
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

bool isStrobogrammatic(string num) {
  if (0 == num.size()) {
    return false;
  }

  std::unordered_map<char, char> stroMap;
  stroMap['6'] = '9';
  stroMap['9'] = '6';
  stroMap['0'] = '0';
  stroMap['1'] = '1';
  // stroMap['8'] = '8';
  stroMap.insert(std::pair<char, char>('8', '8'));

  int i = 0, j = num.size() - 1;
  while (i <= j) { //i == j must check to ensure the odd situation where only 0 1 8 could exist in the middle position
    if (stroMap.find(num[i]) == stroMap.end()) {
      return false;
    }

    if (stroMap[num[i]] != num[j]) {
      return false;
    }
    i++;
    j--;
  }

  return true;
}
*/
