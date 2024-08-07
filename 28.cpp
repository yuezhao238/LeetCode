#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next(haystack.size() + needle.size() + 1);
        int j = -1;
        next[0] = -1;
        string concat = needle + "#" + haystack;
        for (int i = 1; i < concat.size(); i++) {
            while (j >= 0 && concat[i] != concat[j+1]) j = next[j];
            if (concat[i] == concat[j+1]) j++;
            next[i] = j;
            if (next[i] == needle.size() - 1) return i - needle.size() * 2;
        }
        return -1;
    }
};

int main() {
    string haystack = "hello", needle = "ll";
    Solution s;
    cout << s.strStr(haystack, needle) << endl;
}