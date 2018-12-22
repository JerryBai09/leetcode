//
// Created by jerrybai on 2018-12-22.
//

/**********************************************************************
 *
 * Description:
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * You may assume nums1 and nums2 cannot be both empty.
 *
 *
 * Example 1:
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 *
 * Example 2:
 *
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 *
 *
***********************************************************************/

// Solution:
//
// Recursive approach solution:
//
// Median divides array to two sub parts, and the left part is always less or equal than the right part.
//
// Algorithm:
//
// 1.Using the shorter array as the target array to divide by binary search motivation. So swap to array if needed.
// 2.Divide the target array by middle point. To make sure the median attribute, the next array should be divide by position (m + n + 1)/2,
//    as the merged array's candidate median position is (m+n+1)/2.
// 3.Calculate the four num of breaking points. The candidate median is decided by max(LeftX, LeftY) and min(RightX, RightY)
// 4.If two left parts both less or equal than both two right parts, median has been found. If length of merged array is odd,
//   median is max of two Left parts. Otherwise, median is the average of max left parts and min right parts.
// 5.If maxLeftX > minRightY, that means divide point of X should move left, and the target range should be the left part.
//   So update right to partX
// 6.If minRightX < maxLeftY, that means partX should move right to increase, the target range should be the right part.
//   So update left to partX + 1
// 7.For edge condition, if the divide part of array is null, the set the bound value to INT_MIN or INT_MAX to keep the comparision effective.
//
//

// Time Complexity O(log(m+n)), in fact O(log(min(m, n)))
// Space Complexity O(1)
//

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int left = 0, right = m;
        while (left <= right)
        {
            int partX = left + (right - left) / 2;
            int partY = (m + n + 1)/2 - partX;
            int maxLeftX = partX - 1 < 0 ? INT_MIN : nums1[partX - 1];
            int minRightX = partX + 1 > m ? INT_MAX : nums1[partX];
            int maxLeftY = partY - 1 < 0 ? INT_MIN : nums2[partY -1];
            int minRightY = partY + 1 > n ? INT_MAX : nums2[partY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX)
            {
                double ans = 0.0;
                if ((m + n) % 2 == 0)
                {
                    ans = (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                }
                else
                {
                    ans = max(maxLeftX, maxLeftY);
                }

                return ans;
            }
            else if (maxLeftX > minRightY)
            {
                right = partX;
            }
            else if (minRightX < maxLeftY)
            {
                left = partX + 1;
            }
        }

        return 0.0;
    }
};
