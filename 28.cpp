#include <string>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void getNext(int* next, string needle) {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < needle.size(); i++) {
            while (j >= 0 && needle[i] != needle[j + 1]) {
                j = next[j];
            }
            if (needle[j + 1] == needle[i]) {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        vector<int> next(needle.size());
        getNext(&next[0], needle);
        // for (auto i : next) {
        //     cout<<i<<" ";
        // }
        int i = 0, j = -1;
        for (i = 0; i < haystack.size(); i++) {
            while (j >= 0 && haystack[i] != needle[j + 1]) {
                j = next[j];
            }
            if (haystack[i] == needle[j + 1]) {
                j++;
            }
            if (j == needle.size() - 1) {
                return i - j;
            }
        }
        
        return -1;
    }
};

int main() {
    string haystack = "aabaabaafa", needle = "aabaaf";
    Solution s;
    cout << s.strStr(haystack, needle) << endl;
}