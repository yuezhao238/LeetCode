#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int biSearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = nums.size() - 1;
        int res = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target || (nums[mid] == target && lower)) {
                right = mid - 1;
                res = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = biSearch(nums, target, true);
        int right = biSearch(nums, target, false) - 1;
        if (left <= right && right < nums.size() && nums[left] == target && nums[right] == target) return {left, right};
        return {-1, -1};
    }
};

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> res = Solution().searchRange(nums, target);
    cout << res[0] << ' ' << res[1] << endl;
}