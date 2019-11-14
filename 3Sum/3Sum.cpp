//
// Created by 白俊彦 on 2019-11-15.
//

// Find all triplets which gives the sum of 0

#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>>  result;
    if (nums.size() < 3) return result;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            // search if condition match
            int cur = nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                if (cur + nums[l] + nums[r] > 0) {
                    r--;
                } else if (cur + nums[l] + nums[r] < 0) {
                    l++;
                } else {
                    result.push_back({cur, nums[l], nums[r]});
                    l++;
                    r--;
                }
            }
        }
    }

    return result;
}



int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}