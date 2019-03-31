//
// Created by jerrybai on 2019-03-31.
//

/**********************************************************************
 *
 * Description:
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 *
 * Example 1:
 *
 * Example:
 *
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 *
 *
***********************************************************************/

// Solution:
//
// Brute Force:
//
// Compare the area of each two combination, find out the max area pair.
// Time complexity O(n^2)
//
//
// Two pointers move like merge sort, from the longest x distance, move and get closer, until two pointers meet.
// Algorithm:
//
// 1.Two pointers respectively point to the left and right side of array.
// 2.Calculate the current area of two points, which decides by the x distance and the min of two points(arr[left] and arr[right]).
// 3.Compare the two values, and pointers move towards the bigger one.
// 4.When two pointers meet, return the max area.
// 5.Further explanation see https://leetcode.com/problems/container-with-most-water/discuss/6099/Yet-another-way-to-see-what-happens-in-the-O(n)-algorithm
//

// Time Complexity O(n)
// Space Complexity O(1)
//


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxarea = 0;
        while(left < right)
        {
            maxarea = max(maxarea, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxarea;
    }
};

