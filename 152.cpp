#include<bits/stdc++.h>

using namespace std;

class Solution {
// pay attention to case [0,10,10,10,10,10,10,10,10,10,-10,10,10,10,10,10,10,10,10,10,0], long or long long can't represent the tmp val, we can use double even if sizeof(double) == sizeof(long long), double use a sci cnt presentation.
public:
    // int maxProduct(vector<int>& nums) {
    //     vector<double> maxF(nums.begin(), nums.end());
    //     vector<double> minF(nums.begin(), nums.end());
    //     for (int i = 1; i < nums.size(); i++) {
    //         maxF[i] = max(maxF[i-1] * nums[i], max((double)nums[i], minF[i-1] * nums[i]));
    //         minF[i] = min(minF[i-1] * nums[i], min((double)nums[i], maxF[i-1] * nums[i]));
    //     }
    //     return *max_element(maxF.begin(), maxF.end());
    // }
    int maxProduct(vector<int>& nums) {
        double maxF = nums[0], minF = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            double tmpMaxF = maxF;
            maxF = max(maxF * nums[i], max((double)nums[i], minF * nums[i]));
            minF = min(minF * nums[i], min((double)nums[i], tmpMaxF * nums[i]));
            res = max((int)maxF, res);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {2,3,-2,4};
    cout << Solution().maxProduct(nums) << endl;
}