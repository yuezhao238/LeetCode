#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int Max = *max_element(nums.begin(), nums.end());
        int V = sum /= 2;
        if (Max > V) return false;
        vector<vector<int>> F(nums.size() + 1, vector<int>(V + 1));
        fill(F[0].begin(), F[0].end(), -1);
        F[0][0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= V; j++) {
                if (F[i-1][j] >= 0) F[i][j] = 1;
                else F[i][j] = -1;
            }
            for (int j = 0; j <= V - nums[i-1]; j++) if (F[i][j] > 0) F[i][j+nums[i-1]] = max(F[i][j+nums[i-1]], F[i][j] - 1);
        }
        return F[nums.size()][V] >= 0;
    }
};

int main() {
    vector<int> nums = {1,5,11,5};
    cout << Solution().canPartition(nums) << endl;
}