#include <bits/stdc++.h>

using namespace std;

struct direction {
    int dx, dy;
    direction(int dx, int dy) : dx(dx), dy(dy) {}
};

direction directions[] = {direction(0, 1), direction(1, 0), direction(0, -1), direction(-1, 0)};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        if (n % 2) result[n / 2][n / 2] = n * n;
        int it_cnt = 0, ele_per_it = n - 1;
        int start_x = 0, start_y = 0;
        int i = 1;
        while (ele_per_it >= 0) {
            direction dir = directions[it_cnt % 4];
            for (int j = 0; j < ele_per_it; j++) {
                result[start_x][start_y] = i++;
                start_x += dir.dx;
                start_y += dir.dy;
            }
            it_cnt++;
            if (it_cnt % 4 == 0) {
                ele_per_it -= 2;
                start_x-=dir.dx;
                start_y-=dir.dy;
                direction new_dir = directions[it_cnt % 4];
                start_x += new_dir.dx;
                start_y += new_dir.dy;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> res = sol.generateMatrix(6);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
    res = sol.generateMatrix(5);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}