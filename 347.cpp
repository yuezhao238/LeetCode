#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;
        for (int num : nums) m[num]++;
        for (auto kv : m) q.push(make_pair(kv.second, kv.first));
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> res = Solution().topKFrequent(nums, k);
    for (int a : res) cout << a << ' ';
    cout << endl;
}