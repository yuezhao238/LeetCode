#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // // OOM
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     unordered_map <int, int> map;
    //     vector<vector<int>> res;
    //     for (int i = 0; i < nums.size(); i++) map.insert(pair<int, int>(nums[i], i));
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = 0; j < nums.size(); j++) {
    //             if (i == j) continue;
    //             int key = nums[i] + nums[j];
    //             auto iter = map.find(-key);
    //             if (iter != map.end()) {
    //                 if (i == iter->second || j == iter->second) continue;
    //                 res.push_back(vector<int>({nums[i], nums[j], nums[iter->second]}));
    //             }
    //         }
    //     }

    //     for (int i = 0; i < res.size(); i++) {
    //         sort(res[i].begin(), res[i].end());
    //     }
    //     sort(res.begin(), res.end());
    //     res.erase(unique(res.begin(), res.end()), res.end());
    //     return res;
    // }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return res;
            }
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1, right = nums.size() - 1;
            while (right > left) {
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (right > left && nums[left] == nums[left+1]) left++;
                    while (right > left && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
            }
        }
        // // wrong?
        // for (int i = 0; i < res.size(); i++) {
        //     sort(res[i].begin(), res[i].end());
        // }
        // sort(res.begin(), res.end());
        // res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = Solution().threeSum(nums);
    for (auto a : res) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
}