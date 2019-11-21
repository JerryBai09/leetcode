//
// Created by JerryBai on 2019-11-17.
//

/*******************************************************************************************************
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
 * ou may assume all four edges of the grid are all surrounded by water.
 *
 * Example 1:
 *
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Output: 1
 * Example 2:
 *
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 *
 * Output: 3
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/number-of-islands
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 *
 ******************************************************************************************************/

// In this problem, count the number of islands is equal to find out the number of connected areas which format by
// all adjacent '1'
// DFS could be used to find the answer
//
// The procedure of DFS:
// 1. In main search function:
//    Find all paths from each right start and count the paths
// 2. In DFS function:
//    Deal all terminate situations first and return
//    Mark current position as visited
//    For all four directions of current pos:
//        do DFS for each new pos
//
// Complexity:
// Time: O(mn) all elements of the grid
// Space: O(mn) marked all position of grid if the element has been visited
//

class Solution {
public:
    vector <vector<int>> directions = {{0,  1}, {0,  -1}, {1,  0}, {-1, 0}};

    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>>& marked) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || marked[i][j] || grid[i][j] == '0') {
            return;
        }

        marked[i][j] = true;

        // dfs for the adjacent position
        for (auto dir : directions) {
            int new_x = i + dir[0];
            int new_y = j + dir[1];
            dfs(grid, new_x, new_y, marked);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
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
};
