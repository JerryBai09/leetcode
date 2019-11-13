//
// Created by 白俊彦 on 2019-11-14.
//

// board =
// [
// ['A','B','C','E'],
// ['S','F','C','S'],
// ['A','D','E','E']
// ]
//
// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/word-search
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


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