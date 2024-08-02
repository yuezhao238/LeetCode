#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // int maxProfit(vector<int>& prices) {
    //     int res = 0;
    //     for (int i = 1; i < prices.size(); i++) {
    //         if (prices[i] > prices[i - 1]) res += prices[i] - prices[i - 1];
    //     }
    //     return res;
    // }
    int maxProfit(vector<int>& prices) {
        int arr[2][prices.size()];
        memset(arr, 0, sizeof(arr));
        arr[1][0] -= prices[0];
        for (int i = 1; i < prices.size(); i++) {
            arr[0][i] = max(prices[i] + arr[1][i-1], arr[0][i-1]);
            arr[1][i] = max(arr[0][i-1] - prices[i], arr[1][i-1]);
        }
        return arr[0][prices.size()-1];
    }
};

int main() {
    vector<int>prices = {7, 1, 5, 3, 6, 4};
    cout << Solution().maxProfit(prices) << endl;
}