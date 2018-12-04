//
// Created by jerrybai on 2018-12-04.
//

/**********************************************************************
*
* Exercise:
*
* Given an array of integers, return indices of the two numbers such that they add up to a specific target.
*
* You may assume that each input would have exactly one solution, and you may not use the same element twice.
*
*
* Example:
*
* Given nums = [2, 7, 11, 15], target = 9,
*
* Because nums[0] + nums[1] = 2 + 7 = 9,
* return [0, 1].
*
***********************************************************************/

// Solution:
//
// Brute search complement:
//
// for each elements in nums, assume current one is part of result, find the complement
// in all rest elements, return these two indices
//
// Time Complexity O(n^2)


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        for (size_t i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            for (size_t j = i+1; j < nums.size(); j++)
            {
                if (complement == nums[j])
                {
                    indices.push_back(j);
                    indices.push_back(i);
                    return indices;
                }
            }
        }
        return indices;
    }
};
