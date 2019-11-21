//
// Created by 白俊彦 on 2019-11-22.
//

#include <vector>
#include <iostream>

using namespace std;

vector <vector<int>> directions = {{0,  1}, {0,  -1}, {1,  0}, {-1, 0}};

void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>>& marked) {
    // deal all terminate condition
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || marked[i][j] || grid[i][j] == '0') {
        return;
    }

    // mark current position
    marked[i][j] = true;

    // dfs for the adj position
    for (auto dir : directions) {
        int new_x = i + dir[0];
        int new_y = j + dir[1];
        dfs(grid, new_x, new_y, marked);
    }
}

int numIslands(vector<vector<char>> &grid) {
    if (grid.size() == 0) return 0;

    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> marked(m ,vector<bool>(n, false));
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] != '0' && !marked[i][j]) {
                dfs(grid, i, j, marked);
                count++;
            }
        }
    }

    return count;
}

int main() {
    vector<vector<char>> grid1 = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'} };
    cout << "Num of Island1 " << numIslands(grid1) << endl;

    vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'} };
    cout << "Num of Island2 " << numIslands(grid2) << endl;

    vector<vector<char>> grid3 = {{}, {}, {}, {} };
    cout << "Num of Island3 " << numIslands(grid3) << endl;

    return 0;
}