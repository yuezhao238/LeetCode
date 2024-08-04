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
    stack<TreeNode*>stk;
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* tmp = root;
        while (!stk.empty() || tmp != nullptr) {
            while (tmp != nullptr) {
                stk.push(tmp);
                tmp = tmp->left;
            }
            tmp = stk.top();
            stk.pop();
            k--;
            if (!k) return tmp->val;
            tmp = tmp->right;
        }
        return 0; // unarrivable
    }
};

int main() {
    TreeNode* root = new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), new TreeNode(4));
    int k = 1;
    cout << Solution().kthSmallest(root, k) << endl;
}