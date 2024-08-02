#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // int subarraySum(vector<int>& nums, int k) {
    //     vector<int>accumulated;
    //     accumulated.push_back(0);
    //     for (auto a : nums) {
    //         accumulated.push_back(accumulated.back() + a);
    //     }
    //     int left = 0, right = accumulated.size() - 1, res = 0;
    //     for (right; right >= 0; right--) {
    //         for (left = 0; left < right; left++) {
    //             if (accumulated[right] - accumulated[left] == k) res++;
    //         }
    //     }
    //     return res;
    // }
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        m[0] = 1;
        int accumulated = 0, res = 0;
        for (int num : nums) {
            accumulated += num;
            if (m.count(accumulated - k)) res+=m[accumulated-k];
            m[accumulated]++;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,1,1};
    int k = 2;
    cout << Solution().subarraySum(nums, k) << endl;
}