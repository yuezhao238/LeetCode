#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (!s.size()) return 0;
        unordered_map<char, int>m;
        int res = 0;
        int head = 0;
        for (int i = 0; i < s.size(); i++) {
            if (m.count(s[i])) head = max(m[s[i]] + 1, head);
            res = max(res, i - head + 1);
            m[s[i]] = i;
        }
        return res;
    }
};

int main() {
    string s = "au";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
}