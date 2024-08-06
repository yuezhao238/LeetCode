#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    // void dfs(int cur, vector<int>& nums) {
    //     if (cur == nums.size()) {
    //         res.push_back(tmp);
    //         return;
    //     }
    //     tmp.push_back(nums[cur]);
    //     dfs(cur + 1, nums);
    //     tmp.pop_back();
    //     dfs(cur + 1, nums);
    // }
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     dfs(0, nums);
    //     return res;
    // }


    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            tmp.clear();
            for (int i = 0; i < n; i++) if (mask & (1 << i)) tmp.push_back(nums[i]);
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = Solution().subsets(nums);
    for (auto a : res) {
        for (auto b : a) cout << b << ' ';
        cout << endl;
    }
}