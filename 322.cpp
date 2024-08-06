#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // unordered_map<int, int>cache;
    // int dfs(vector<int>& coins, int amount) {
    //     if (amount < 0) return -1;
    //     if (amount == 0) return 0;
    //     if (cache.count(amount)) return cache[amount];
    //     int res = INT_MAX;
    //     for (int c : coins) {
    //         int tmp = coinChange(coins, amount - c);
    //         res = (tmp < 0) ? res : min(res, tmp + 1);
    //     }
    //     cache[amount] = (res == INT_MAX) ? -1 : res;
    //     return (res == INT_MAX) ? -1 : res;
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     if (amount == 0) return 0;
    //     return dfs(coins, amount);
    // }

    vector<int> cache;
    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (cache[amount-1] != 0) return cache[amount-1];
        int res = INT_MAX;
        for (int c : coins) {
            int tmp = dfs(coins, amount - c);
            res = (tmp < 0) ? res : min(res, tmp + 1);
        }
        cache[amount-1] = (res == INT_MAX) ? -1 : res;
        return (res == INT_MAX) ? -1 : res;
    }
    int coinChange(vector<int>& coins, int amount) {
        cache.resize(amount);
        return dfs(coins, amount);
    }
};

int main() {
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout << Solution().coinChange(coins, amount) << endl;
}