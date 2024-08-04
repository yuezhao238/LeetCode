#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int r = nums[0], n = 0;
        for (int i = 1; i < nums.size(); i++) {
            int tmp = n + nums[i];
            n = max(n, r);
            r = tmp;
        }
        return max(n, r);
    }
};

int main() {
    vector<int> nums = {1,2,3,1};
    cout << Solution().rob(nums) << endl;
}