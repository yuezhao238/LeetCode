#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> res(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++) {
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = Solution().dailyTemperatures(temperatures);
    for (auto iter = res.begin(); iter != res.end(); iter++) {
        cout << *iter << " ";
    }
}