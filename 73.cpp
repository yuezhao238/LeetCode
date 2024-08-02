#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row;
        unordered_set<int> col;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (!matrix[i][j]) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for (auto r : row) {
            for (int j = 0; j < matrix[0].size(); j++) matrix[r][j] = 0;
        }
        for (auto c : col) {
            for (int i = 0; i < matrix.size(); i++) matrix[i][c] = 0;
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    Solution().setZeroes(matrix);
    for (auto a : matrix) {
        for (auto b : a) {
            cout << b << ' ';
        }
        cout << endl;
    }
}