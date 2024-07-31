#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        do {
            int m = (l + r) / 2;
            if (nums[m] == target) return m;
            if (nums[m] < target) l = m + 1;
            else r = m;
        } while (l != r);
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5};
    cout << sol.search(nums, 5) << endl;
    return 0;
}