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
    // // if a tree is symmetric, its left subtree's preorder traversal equals to the postorder traversal of its right subtree.
    // vector<pair<int, int>>left;
    // vector<pair<int, int>>right;
    // bool isSymmetric(TreeNode* root) {
    //     traverse(root->left, left, 0, 0);
    //     traverse(root->right, right, 1, 0);
    //     return left == right;
    // }
    // void traverse(TreeNode* root, vector<pair<int, int>>&container, bool tp, int depth) {
    //     if (root == nullptr) return;
    //     if (tp) {
    //         traverse(root->left, container, tp, depth + 1);
    //         container.push_back(make_pair(root->val, depth));
    //         traverse(root->right, container, tp, depth + 1);
    //     }
    //     else {
    //         traverse(root->right, container, tp, depth + 1);
    //         container.push_back(make_pair(root->val, depth));
    //         traverse(root->left, container, tp, depth + 1);
    //     }
    // }
    bool check(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return (left->val == right->val) && check(left->left, right->right) && check(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    cout << Solution().isSymmetric(root) << endl;
}