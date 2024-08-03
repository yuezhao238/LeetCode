#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // // TLE
    // vector<int> findAnagrams(string s, string p) {
    //     if (s.size() < p.size()) return {};
    //     int winSize = p.size();
    //     sort(p.begin(), p.end());
    //     vector<int> res;
    //     for (int i = 0, pos = p.size() - 1; i < s.size() - p.size() + 1; i++, pos++) {
    //         string tmp = s.substr(i, winSize);
    //         sort(tmp.begin(), tmp.end());
    //         if (tmp == p) res.push_back(i);
    //     }
    //     return res;
    // }

    // border line
    // vector<int> findAnagrams(string s, string p) {
    //     if (s.size() < p.size()) return {};
    //     int winSize = p.size();
    //     sort(p.begin(), p.end());
    //     vector<int> res;
    //     for (int i = 0, pos = p.size() - 1; i < s.size() - p.size() + 1; i++, pos++) {
    //         string tmp = s.substr(i, winSize);
    //         sort(tmp.begin(), tmp.end());
    //         if (tmp == p) {
    //             res.push_back(i);
    //             while (i < s.size() - p.size() + 1) {
    //                 i++;
    //                 pos++;
    //                 if (s[i-1] == s[pos]) res.push_back(i);
    //                 else break;
    //             }
    //         }
    //     }
    //     return res;
    // }

    vector<int> findAnagrams(string s, string p) {
        int slen = s.size(), plen = p.size();
        if (slen < plen) return {};
        vector<int> sAlphaCount(26);
        vector<int> pAlphaCount(26);
        vector<int> res;
        for (int i = 0; i < plen; i++) {
            sAlphaCount[s[i] - 'a']++;
            pAlphaCount[p[i] - 'a']++;
        }
        if (sAlphaCount == pAlphaCount) res.push_back(0);
        for (int i = 1, pos = plen; i < slen - plen + 1; i++, pos++) {
            sAlphaCount[s[i-1] - 'a']--;
            sAlphaCount[s[pos] - 'a']++;
            if (sAlphaCount == pAlphaCount) res.push_back(i);
        }
        return res;
    }
};

int main() {
    string s = "cbaebabacd", p = "abc";
    vector<int> res = Solution().findAnagrams(s, p);
    for (auto a : res) cout << a << ' ';
    cout << endl;
}