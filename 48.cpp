#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int r = 0; r < n / 2; r++) {
            for (int p = r; p < n - 1 - r; p++) {
                int ar, ac, br, bc, cr, cc, dr, dc;
                ar = r, ac = p;
                br = p, bc = n - 1 - r;
                cr = n - 1 - r, cc = n - 1 - p;
                dr = n - 1 - p, dc = r;
                int tmp = matrix[ar][ac];
                matrix[ar][ac] = matrix[dr][dc];
                matrix[dr][dc] = matrix[cr][cc];
                matrix[cr][cc] = matrix[br][bc];
                matrix[br][bc] = tmp;
            }
        }
    }
};

int main() {
    vector<vector<int>>matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    Solution().rotate(matrix);
    for (auto a : matrix) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
    matrix = {
        {5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},
        {15,14,12,16}
    };
    Solution().rotate(matrix);
    for (auto a : matrix) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
}