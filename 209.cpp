#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, end = 0, sum = 0, min_len = INT_MAX;
        for (end; end < nums.size(); end++) {
            sum += nums[end];
            while (sum >= target) {
                min_len = min(min_len, end - start + 1);
                sum -= nums[start++];
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << sol.minSubArrayLen(7, nums) << endl;
    return 0;
}