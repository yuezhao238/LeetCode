#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;
    // void dfs(string& cur, int open, int close, int n) {
    //     if (cur.size() == n * 2) {
    //         res.push_back(cur);
    //         return;
    //     }
    //     if (open < n) {
    //         cur.push_back('(');
    //         dfs(cur, open + 1, close, n);
    //         cur.pop_back();
    //     }
    //     if (close < open) {
    //         cur.push_back(')');
    //         dfs(cur, open, close + 1, n);
    //         cur.pop_back();
    //     }
    // }
    // vector<string> generateParenthesis(int n) {
    //     string cur;
    //     dfs(cur, 0, 0, n);
    //     return res;
    // }

    void dfs(string& cur, int leftNum, int n) {
        if (cur.size() == n * 2) {
            res.push_back(cur);
            return;
        }
        if (leftNum < n) {
            cur.push_back('(');
            dfs(cur, leftNum + 1, n);
            cur.pop_back();
        }
        if (cur.size() - leftNum < leftNum) {
            cur.push_back(')');
            dfs(cur, leftNum, n);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur;
        dfs(cur, 0, n);
        return res;
    }
};

int main() {
    int n = 3;
    vector<string> res = Solution().generateParenthesis(n);
    for (auto a : res) cout << a << ' ';
    cout << endl;
}