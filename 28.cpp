#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next(haystack.size() + needle.size() + 1);
        int j = 0;
        next[0] = 0;
        string concat = needle + "#" + haystack;
        for (int i = 1; i < concat.size(); i++) {
            while (j > 0 && concat[i] != concat[j]) j = next[j-1];
            if (concat[i] == concat[j]) j++;
            next[i] = j;
            if (next[i] == needle.size()) return i - needle.size() * 2;
        }
        return -1;
    }
};

int main() {
    string haystack = "hello", needle = "ll";
    Solution s;
    cout << s.strStr(haystack, needle) << endl;
}