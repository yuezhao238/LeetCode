#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int k = nums.size() - 1, l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (nums[l] * nums[l] < nums[r] * nums[r]) result[k--] = nums[r] * nums[r--];
            else result[k--] = nums[l] * nums[l++];
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> res = sol.sortedSquares(nums);
    return 0;
}