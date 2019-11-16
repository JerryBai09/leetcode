//
// Created by Jerry Bai on 2019-11-14.
//

/*********************************************************************
 * Description:
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 *
 * Example:
 *
 *  board =
 *  [
 *  ['A','B','C','E'],
 *  ['S','F','C','S'],
 *  ['A','D','E','E']
 *  ]
 *
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/word-search
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**********************************************************************/

// Solution
//
// This is a problem which needs search a two-dimension plane to find a specific combination of words.
// DFS + backtrace should be the first solution of these search problems.
//
// The workflow for DFS
// 1) For each search, first eval the terminate condition
// 2) Deal if some boarder conditions match
// 3) Mark the current position as visited
// 4) Search around the four directions of current position to find if there are solutions
// 5) Restore the marked position for the next backtrace
// 6) Return the result
//
// A pseudo code of DFS
// bool dfs for input position:
//    if the whole search is over:
//          return the result
//    if target search position is beyond the board:
//          end search and return the result
//    mark the search pos as visited
//    call DFS on all four directions around the current pos
//    restore the marked position
//    return search result
//
// For DFS caller(always main func), only should start the dfs at a initial position and the function will be called
// by recursive until all positions have been searched
//
// Complexity
// Time: O(mn), m is the number of characters in board, n is the length of word
// Space: O(1)




// DFS 搜索的一种形式
bool dfs(vector<vector<char>>& board, int i, int j, int count, string word) {
    if (count == word.length()) {
        return true;
    }

    if (i < 0 || i >= board.size() || j < 0 || j>= board[i].size()
        || board[i][j] != word[count]) {
        return false;
    }

    char temp = board[i][j];
    board[i][j] = ' ';
    bool found = dfs(board, i + 1, j, count + 1, word)
                 || dfs(board, i - 1, j, count + 1, word)
                 || dfs(board, i, j + 1, count + 1, word)
                 || dfs(board, i, j - 1, count + 1, word);

    board[i][j] = temp;

    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    if (word.size() == 0) return false;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == word[0] && dfs(board, i, j, 0, word)) {
                return true;
            }
        }
    }

    return false;
}