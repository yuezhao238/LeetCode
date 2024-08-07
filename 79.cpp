#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int index, int row, int col) {
        if (index == word.size()) return true;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) return false;
        if (board[row][col] != word[index]) return false;
        auto board_val = board[row][col];
        board[row][col] = '0';
        bool result = false;
        result = result || dfs(board, word, index + 1, row - 1, col);
        result = result || dfs(board, word, index + 1, row + 1, col);
        result = result || dfs(board, word, index + 1, row, col - 1);
        result = result || dfs(board, word, index + 1, row, col + 1);
        board[row][col] = board_val;
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) if (board[r][c] == word[0] && dfs(board, word, 0, r, c)) return true;
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    cout << Solution().exist(board, word) << endl;
}