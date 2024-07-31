#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, fast = 0;
        for (fast; fast < nums.size(); fast++) {
            if (nums[fast] != val) nums[slow++] = nums[fast];
        }
        return slow;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    cout << sol.removeElement(nums, 2) << endl;
    return 0;
}