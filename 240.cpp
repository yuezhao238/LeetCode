#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int bottom = matrix.size() - 1, left = 0;
        while (bottom >= 0 && left <= matrix[0].size() - 1) {
            if (matrix[bottom][left] > target) bottom--;
            else if (matrix[bottom][left] < target) left++;
            else return true;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    int target = 20;
    cout << Solution().searchMatrix(matrix, target) << endl;
}