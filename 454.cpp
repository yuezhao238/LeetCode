#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> countAB;
        for (int u: A) {
            for (int v: B) countAB[u + v]++;
        }
        int ans = 0;
        for (int u: C) {
            for (int v: D) if (countAB.count(-u - v)) ans += countAB[-u - v];
        }
        return ans;
    }
};

int main() {
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0,2};
    cout << Solution().fourSumCount(nums1, nums2, nums3, nums4) << endl;
}