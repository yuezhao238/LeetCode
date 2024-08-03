#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // // {9,8,9,8}, 3, TLE??? :(
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> res;
    //     int Max = *max_element(nums.begin(), nums.begin() + k);
    //     res.push_back(Max);
    //     int maxCnt = count(nums.begin(), nums.begin() + k, Max);
    //     int left = nums[0];
    //     for (int i = 1; i < nums.size() - k + 1; i++) {
    //         if (left != Max) {
    //             if (nums[i+k-1] > Max) {
    //                 Max = nums[i+k-1];
    //                 maxCnt = 1;
    //             }
    //         }
    //         else {
    //             maxCnt--;
    //             if (!maxCnt) {
    //                 Max = *max_element(nums.begin() + i, nums.begin() + i + k);
    //                 maxCnt = count(nums.begin() + i, nums.begin() + i + k, Max);
    //             }
    //         }
    //         left = nums[i];
    //         res.push_back(Max);
    //     }
    //     return res;
    // }
    vector<int> maxSlidingWindow(vector<int> nums, int k) {
        priority_queue<pair<int, int>>q;
        for (int i = 0; i < k; i++) {
            q.emplace(nums[i], i);
        }
        vector<int> res = {q.top().first};
        for (int i = k; i < nums.size(); i++) {
            q.emplace(nums[i], i);
            while (q.top().second < i - k) {
                q.pop();
            }
            res.push_back(q.top().first);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = Solution().maxSlidingWindow(nums, k);
    for (auto a : res) cout << a << ' ';
    cout << endl;
}