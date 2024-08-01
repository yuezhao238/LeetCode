#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<string, bool>memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        auto iter = memo.find(s);
        if (iter != memo.end()) return iter->second;
        bool res = false;
        for (string a : wordDict) {
            if (s == a) return true;
            if (s.substr(0, a.size()) == a) {
                bool ans = wordBreak(s.substr(a.size(), s.size() - a.size() + 1), wordDict);
                memo.insert(pair<string, bool>(s, ans));
                if (res || ans) return true;
            }
        }
        return res;
    }
};

int main() {
    string s = "cars";
    vector<string> wordDict = {"car", "ca", "rs"};
    cout << Solution().wordBreak(s, wordDict) << endl;
    s = "applepenapple";
    wordDict = {"apple", "pen"};
    cout << Solution().wordBreak(s, wordDict) << endl;
}