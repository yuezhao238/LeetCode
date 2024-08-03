#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto a : nums) res ^= a;
        return res;
    }
};

int main() {
    vector<int> nums = {2,2,1};
    cout << Solution().singleNumber(nums) << endl;
}