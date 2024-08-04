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
    vector<int> res;
    // vector<int> inorderTraversal(TreeNode* root) {
    //     if (root == nullptr) return res;
    //     inorderTraversal(root->left);
    //     res.push_back(root->val);
    //     inorderTraversal(root->right);
    //     return res;
    // }

    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        while (!stk.empty() || root != nullptr) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            res.push_back(root->val);
            stk.pop();
            root = root->right;
        }
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> res = Solution().inorderTraversal(root);
    for (int a : res) cout << a << ' ';
    cout << endl;
}