#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n  - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midRow = mid / n, midCol = mid % n;
            if (matrix[midRow][midCol] < target) left = mid + 1;
            else if (matrix[midRow][midCol] > target) right = mid - 1;
            else return true;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int target = 3;
    cout << Solution().searchMatrix(matrix, target) << endl;
}