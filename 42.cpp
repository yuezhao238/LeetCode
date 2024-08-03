#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[stk.top()] < height[i]) {
                int mid = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int left = stk.top();
                int depth = min(height[i], height[left]) - height[mid];
                res += (i - left - 1) * depth;
            }
            stk.push(i);
        }
        return res;
    }
};

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << Solution().trap(height) << endl;
}