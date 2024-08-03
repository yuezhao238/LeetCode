#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>>q;
        for (int num : nums) q.push(num);
        for (int i = 1; i < k; i++) q.pop();
        return q.top();
    }
};

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << Solution().findKthLargest(nums, k) << endl;
}