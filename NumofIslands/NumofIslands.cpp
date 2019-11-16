//
// Created by JerryBai on 2019-11-17.
//

#include <vector>
#include <iostream>

using namespace std;

vector <vector<int>> directions = {{0,  1},
                                   {0,  -1},
                                   {1,  0},
                                   {-1, 0}};

void search_island(vector <vector<char>> &grid, int i, int j, int& count, vector <vector<bool>> &marked) {
    // Over the boarder of grid
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) {
        return;
    }
    if (grid[i][j] == '0' || marked[i][j]) {
        marked[i][j] = true;
        return;
    }

    marked[i][j] = true;
    bool end_flag = true;
    for (int pos = 0; pos < directions.size(); pos++) {
        int new_x = i + directions[pos][0];
        int new_y = j + directions[pos][1];
        if (new_x > 0 && new_x < grid.size() && new_y > 0 && new_y < grid[0].size() &&
            !marked[new_x][new_y] && grid[new_x][new_y] != '0') {
            end_flag = false;
            search_island(grid, new_x, new_y, count, marked);
        }

    }
    if (end_flag) {
        cout << "Pos: " << i << " " << j << endl;
        cout << "Num is " << count << endl;
        count++;
    }
}

int numIslands(vector <vector<char>> &grid) {
    if (grid.size() == 0) return 0;

    int m = grid.size();
    int n = grid[0].size();
    vector <vector<bool>> marked(m, vector<bool>(n, false));

    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            search_island(grid, i, j, count, marked);
        }
    }

    return count;
}


int main() {
    vector<vector<char>> grid1 = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'} };
    cout << "Num of Island " << numIslands(grid1) << endl;

    return 0;
}