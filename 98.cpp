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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* tmp = root;
        long long curr = (long long)INT_MIN - 1;
        while (!stk.empty() || tmp != nullptr) {
            while (tmp != nullptr) {
                stk.push(tmp);
                tmp = tmp->left;
            }
            tmp = stk.top();
            if (tmp->val <= curr) return false;
            else curr = tmp->val;
            stk.pop();
            tmp = tmp->right;
        }
        return true;
    }
};

int main() {
    TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    cout << Solution().isValidBST(root) << endl;
}