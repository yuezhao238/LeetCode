#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int preSum = 1, sufSum = 1;
        vector<int> res(nums.size(), 1);
        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--) {
            res[i] *= preSum;
            res[j] *= sufSum;
            preSum *= nums[i];
            sufSum *= nums[j];
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,2,3,4};
    vector<int> res = Solution().productExceptSelf(nums);
    for (auto a : res) cout << a << ' ';
    cout << endl;
}