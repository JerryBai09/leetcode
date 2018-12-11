//
// Created by jerrybai on 2018-12-11.
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
// Hash map solution:
//
// Using hash map to reduce the search time of each complement's indices.
//
// for each elements in nums, if key complement exists in the hash map, return according value(indices)
// else insert the pair (nums[i], i) into the hash map
//
// Time Complexity O(n) as hash map search is O(1)


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> IndicesMap;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (IndicesMap.find(complement) != IndicesMap.end())
            {
                return {IndicesMap[complement], i};
            }
            IndicesMap.insert(unordered_map<int, int>::value_type(nums[i], i));
        }
    }
};
