#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>m;
        vector<vector<string>> res;
        for (string str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(str);
        }
        for (auto it : m) res.push_back(it.second);
        return res;
    }
};

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = Solution().groupAnagrams(strs);
    for (auto a : res) {
        for (auto b : a) {
            cout << b << ' ';
        }
        cout << endl;
    }
}