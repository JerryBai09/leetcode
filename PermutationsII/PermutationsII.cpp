//
// Created by JerryBai on 2020-01-01.
//

#include <vector>
#include <iostream>

using namespace std;

//Input: [[1,1,2]
//Output:
//[
//[1,1,2],
//[1,2,1],
//[2,1,1]
//]


void backtrack(vector<vector<int> >& perm, vector<int>& temp, vector<int> nums, vector<bool>& used) {
    if (temp.size() == nums.size()) {
        perm.push_back(temp);
    }
    // Using backtrace to list all permutations of input array
    // used is a marker for each elements
    // The whole process is similarly with dfs, and for each
    // handled element, all elements of nums is candidate
    for (int i = 0; i < nums.size(); i++) {
        if (used[i] || (i > 0 && nums[i-1] == nums[i] && !used[i-1])) continue;
        used[i] = true;
        temp.push_back(nums[i]);
        backtrack(perm, temp, nums, used);
        used[i] = false;
        temp.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    if (nums.size() == 0) return {{}};

    vector<vector<int> > res;
    vector<bool> used(nums.size(), false);
    vector<int> temp;
    sort(nums.begin(), nums.end());
    backtrack(res, temp, nums, used);

    return res;
}

int main() {
    vector<int> num1;
    vector<vector<int> > per1 = permuteUnique(num1);
    cout << "per1" << endl;
    for (auto vec : per1) {
        for (auto num : vec) {
            cout << "permutation " << num;
        }
        cout << endl;
    }

    vector<int> num2 = {2, 2, 1, 1};
    vector<vector<int> > per2 = permuteUnique(num2);
    cout << "per2" << endl;
    for (auto vec : per2) {
        for (auto num : vec) {
            cout << num;
        }
        cout << endl;
    }

    return 0;
}