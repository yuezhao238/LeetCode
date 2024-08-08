#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++) last[s[i]-'a'] = i;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i]-'a']);
            if (i == end) {
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};

int main() {
    string s = "ababcbacadefegdehijhklij";
    vector<int> res = Solution().partitionLabels(s);
    for (auto a : res) cout << a << ' ';
    cout << endl;
}