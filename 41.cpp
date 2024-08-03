#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i]-1]) break;
                int target_idx = nums[i] - 1;
                int tmp = nums[i];
                nums[i] = nums[target_idx];
                nums[target_idx] = tmp;
            }
        }
        for (int i = 0; i < nums.size(); i++) if (nums[i] != i + 1) return i + 1;
        return nums.size() + 1;
    }
};

int main() {
    vector<int> nums = {1,2,0};
    cout << Solution().firstMissingPositive(nums) << endl;
}