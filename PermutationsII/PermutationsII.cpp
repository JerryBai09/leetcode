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


void backtrack(vector<int>& vec, int l, int h, vector<vector<int> >& perm) {
    if (l == h) {
        perm.push_back(vec);
    }
    else {
        for (int i = l; i <= h; i++) {
            cout << "l: " << l << " h " << h << " i " << i << endl;
            if (l != i && vec[l] == vec[i]) continue;
            swap(vec[l], vec[i]);
            backtrack(vec, l + 1, h, perm);
            swap(vec[l], vec[i]);
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int> > res;
    if (nums.size() == 0) return {{}};

    backtrack(nums, 0, nums.size() - 1, res);
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