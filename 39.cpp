#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<int>& candidates, int target) {
        if (!target) {
            res.push_back(tmp);
            return;
        }
        for (int a : candidates) {
            if (a > target) continue;
            if (!tmp.empty() && a < tmp.back()) continue;
            tmp.push_back(a);
            dfs(candidates, target - a);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target);
        return res;
    }
};

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> res = Solution().combinationSum(candidates, target);
    for (auto a : res) {
        for (auto b : a) cout << b << ' ';
        cout << endl;
    }
}