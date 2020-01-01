//
// Created by 白俊彦 on 2020-01-01.
//

#include <vector>
#include <iostream>

using namespace std;

//Input: [1,2,3]
//Output:
//[
//[1,2,3],
//[1,3,2],
//[2,1,3],
//[2,3,1],
//[3,1,2],
//[3,2,1]
//]


void permuteOnce(vector<int>& vec, int l, int h, vector<vector<int> >& perm) {
    if (l == h) {
        perm.push_back(vec);
    }
    else {
        for (int i = l; i <= h; i++) {
            swap(vec[l], vec[i]);
            permuteOnce(vec, l + 1, h, perm);
            swap(vec[l], vec[i]);
        }
    }
}

vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > res;
    if (nums.size() == 0) return {{}};

    permuteOnce(nums, 0, nums.size() - 1, res);
    return res;
}

int main() {
    vector<int> num1;
    vector<vector<int> > per1 = permute(num1);
    cout << "per1" << endl;
    for (auto vec : per1) {
        for (auto num : vec) {
            cout << "permutation " << num;
        }
        cout << endl;
    }

    vector<int> num2 = {1, 2, 3};
    vector<vector<int> > per2 = permute(num2);
    cout << "per2" << endl;
    for (auto vec : per2) {
        for (auto num : vec) {
            cout << "permutation " << num;
        }
        cout << endl;
    }

    return 0;
}