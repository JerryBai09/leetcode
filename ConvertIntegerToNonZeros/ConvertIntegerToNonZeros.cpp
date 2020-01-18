//
// Created by Jerry Bai on 2020-01-12.
//

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

// Convert from the mode remaining num so the other part would be 9****
vector<int> getNoZeroIntegers(int n) {
    if (n <= 1) return {};

    string str = to_string(n);
    int base = pow(10, str.size() - 1);
    int remain = n % base;
    for (int i = remain; i <= n/2; i++) {
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

