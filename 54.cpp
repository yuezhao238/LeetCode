#include<bits/stdc++.h>

using namespace std;

struct Direction {
    int drow, dcol;
    Direction(int drow, int dcol) : drow(drow), dcol(dcol) {}
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<Direction> ds = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<int> limrowcol = {n, m - 1};
        int row = 0, col = -1, d = 0;
        
        while (limrowcol[d % 2]) {
            for (int i = 0; i < limrowcol[d % 2]; ++i) {
                row += ds[d].drow;
                col += ds[d].dcol;
                res.push_back(matrix[row][col]);
            }
            limrowcol[d % 2]--;
            d = (d + 1) % 4;
        }
        
        return res;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    vector<int> res = Solution().spiralOrder(matrix);
    for (auto iter = res.begin(); iter != res.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    
    matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    res = Solution().spiralOrder(matrix);
    for (auto iter = res.begin(); iter != res.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}