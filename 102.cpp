#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        queue<pair<int, TreeNode*>> q;
        vector<vector<int>> res(2000);
        TreeNode* tmp;
        int level;
        q.push(make_pair(0, root));
        // res.push_back({root->val});
        while (!q.empty()) {
            tie(level, tmp) = q.front();
            q.pop();
            res[level].push_back(tmp->val);
            if (tmp->left) q.push(make_pair(level + 1, tmp->left));
            if (tmp->right) q.push(make_pair(level + 1, tmp->right));
        }
        res.resize(level + 1);
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    vector<vector<int>> res = Solution().levelOrder(root);
    for (auto a : res) {
        for (auto b : a) cout << b << " ";
        cout << endl;
    }
}