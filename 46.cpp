#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, vector<int>& curr) {
        if (curr.size() == nums.size()) res.push_back(curr);
        for (auto num : nums) {
            if (find(curr.begin(), curr.end(), num) == curr.end()) {
                curr.push_back(num);
                dfs(nums, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>curr;
        dfs(nums, curr);
        return res;
    }
};

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = Solution().permute(nums);
    for (auto a : res) {
        for (auto b : a) cout << b << ' ';
        cout << endl;
    }
}