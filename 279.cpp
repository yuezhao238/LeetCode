#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int>squares;
    unordered_map<int, int>mem;
    int getNum(int n) {
        int res = INT_MAX;
        if (n == 0) return 0;
        if (mem.find(n) != mem.end()) return mem[n];
        for (int i = 0; i < squares.size(); i++) {
            if (squares[i] > n) break;
            int tmp = getNum(n - squares[i]);
            res = min(res, tmp + 1);
        }
        mem[n] = res;
        return res;
    }
    int numSquares(int n) {
        int root = sqrt(n);
        
        for (int i = 1; i <= root; i++) {
            squares.push_back(i * i);
        }
        return getNum(n);
    }
};

int main() {
    int n = 12;
    cout << Solution().numSquares(n) << endl;
}