#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> map;
        int res = 0;
        for (int i = 0; i < s.size() - minSize + 1; i++) {
            string curr = s.substr(i, minSize);
            unordered_set<char> exist(curr.begin(), curr.end());
            if (exist.size() <= maxLetters) {
                map[curr]++;
                res = max(res, map[curr]);
            }
        }
        return res;
    }
};

int main() {
    string s = "aababcaab";
    int maxLetters = 2, minSize = 3, maxSize = 4;
    cout << Solution().maxFreq(s, maxLetters, minSize, maxSize) << endl;
}