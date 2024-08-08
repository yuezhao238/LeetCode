#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int Min = nums[0];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else right = mid - 1;
            Min = min(Min, nums[mid]);
        }
        return Min;
    }
};

int main() {
    vector<int> nums = {3,4,5,1,2};
    cout << Solution().findMin(nums) << endl;
}