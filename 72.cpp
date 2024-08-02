#include <bits/stdc++.h>

using namespace std;


struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Solution {
public:
    // // 1145/1146 passed. OOM :(
    // unordered_map<pair<string, string>, int, pair_hash> m;
    // int minDistance(string word1, string word2) {
    //     if (word1 == "" || word2 == "") return max(word1.size(), word2.size());
    //     if (m.count({word1, word2})) return m[{word1, word2}];
        
    //     int insert_ = minDistance(word1.substr(1), word2) + 1;
    //     int delete_ = minDistance(word1, word2.substr(1)) + 1;
    //     int substitute_ = minDistance(word1.substr(1), word2.substr(1)) + int(word1[0] != word2[0]);
        
    //     m[{word1, word2}] = min({insert_, delete_, substitute_});
    //     return m[{word1, word2}];
    // }
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int dp[m + 1][n + 1];
        for (int i = 0; i <= m; i++) 
            dp[i][0] = i;
        for (int j = 1; j <= n; j++) 
            dp[0][j] = j;
        for (int i = 1; i <= m; i++) 
            for (int j = 1; j <= n; j++) 
            {
                if (word1[i - 1] == word2[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1];
                else 
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    string word1 = "horse", word2 = "ros";
    cout << sol.minDistance(word1, word2) << endl;
    return 0;
}