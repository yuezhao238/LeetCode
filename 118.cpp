#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {{1}};
        for (int i = 1; i < numRows; i++) {
            vector<int> tmp = {1};
            for (int j = 1; j < i; j++) {
                tmp.push_back({res[i-1][j-1] + res[i-1][j]});
            }
            tmp.push_back({1});
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {
    int numRows = 5;
    vector<vector<int>> res = Solution().generate(numRows);
    for (auto a : res) {
        for (auto b : a) {
            cout << b << ' ';
        }
        cout << endl;
    }
}