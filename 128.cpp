#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // // TLE {-1000000000, 1, 2, 3, 9, 1000000000}
    // int longestConsecutive(vector<int>& nums) {
    //     int MAX = *max_element(nums.begin(), nums.end());
    //     int MIN = *min_element(nums.begin(), nums.end());
    //     vector<bool> t(MAX-MIN+1);
    //     for (auto num : nums) t[num-MIN] = true;
    //     int res = 0;
    //     int tmp = 0;
    //     for (auto b : t) {
    //         if (!b) tmp = 0;
    //         else tmp++;
    //         res = max(res, tmp);
    //     }
    //     return res;
    // }
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int>s;
        for (int num : nums) s.insert(num);
        for (int num : s) {
            if (!s.count(num - 1)) {
                int curr = num;
                int tmp = 1;
                while (s.count(curr + 1)) {
                    tmp++;
                    curr++;
                }
                res = max(res, tmp);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout << Solution().longestConsecutive(nums) << endl;
}