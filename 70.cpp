#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // int climbStairs(int n) {
    //     if (n == 1) return 1;
    //     else if (n == 2) return 2;
    //     else {
    //         return climbStairs(n - 1) + climbStairs(n - 2);
    //     }
    // }
    int climbStairs(int n) {
        int nums[46] = {0, 1, 2};
        for (int i = 3; i <= n; i++) {
            nums[i] = nums[i-1] + nums[i-2];
        }
        return nums[n];
    }
};

int main() {
    int n = 3;
    cout << Solution().climbStairs(n) << endl;
}