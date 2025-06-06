#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0, tmp = 0;
        while (right > left) {
            res = max(res, (right - left) * min(height[left], height[right]));
            if (height[right] < height[left]) right--;
            else left++;
        }
        return res;
    }
};

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << Solution().maxArea(height) << endl;
}