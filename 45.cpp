#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, tmpend = 0;
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (maxPos >= i) {
                maxPos = max(maxPos, nums[i] + i);
            }
            if (i == tmpend) {
                tmpend = maxPos;
                res++;
            }
        }
        return res;
    }
};

int main() {
    vector<int>nums = {2,3,1,1,4};
    cout << Solution().jump(nums) << endl;
}