#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};

int main() {
    int n = 2;
    cout << Solution().divisorGame(n) << endl;
}