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
    // int depth(TreeNode* root) {
    //     if (root == nullptr) return 0;
    //     return max(depth(root->left), depth(root->right)) + 1;
    // }
    // int diameterOfBinaryTree(TreeNode* root) {
    //     if (root == nullptr) return 0;
    //     return max(max(depth(root->left) + depth(root->right), diameterOfBinaryTree(root->left)), diameterOfBinaryTree(root->right));
    // }

    int res;
    int depth(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        res = max(res, l + r);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        res = -1;
        depth(root);
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    cout << Solution().diameterOfBinaryTree(root) << endl;
}