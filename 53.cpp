#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        for (int i = 0; i < nums.size(); i++) {
            if (dp.empty()) dp.push_back(nums[i]);
            else dp.push_back(max(dp[i-1] + nums[i], nums[i]));
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int res = Solution().maxSubArray(nums);
    cout << res << endl;
}