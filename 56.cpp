#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b) {
            return a[0] < b[0];
        });
        vector<vector<int>>merged;
        for (auto v : intervals) {
            if (merged.empty()) merged.push_back(v);
            else {
                if (merged.back()[1] >= v[0]) merged.back()[1] = max(merged.back()[1], v[1]);
                else merged.push_back(v);
            }
        }
        return merged;
    }
};

int main() {
    vector<vector<int>> intervals = {
        {1,3}, {2,6}, {8,10}, {15,18}
    };
    intervals = Solution().merge(intervals);
    for (auto a : intervals) {
        for (auto b : a) {
            cout << b << ' ';
        }
        cout << endl;
    }
}