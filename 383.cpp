#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;
        vector<int> cnt(26);
        for (auto & c : magazine) cnt[c - 'a']++;
        for (auto & c : ransomNote) {
            cnt[c - 'a']--;
            if (cnt[c - 'a'] < 0) return false;
        }
        return true;
    }
};

int main() {
    string ransomNote = "a", magazine = "b";
    cout << Solution().canConstruct(ransomNote, magazine) << endl;
}