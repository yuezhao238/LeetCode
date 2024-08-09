#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m.emplace(nums[i], i);
            if (m.count(target - nums[i]) && m[target-nums[i]] != i) return {m[target-nums[i]], i};
        }
        return {};
    }
};

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> res = Solution().twoSum(nums, target);
    for (auto a : res) cout << a << ' ';
    cout << endl;
}