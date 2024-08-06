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
    int pathSumFrom(TreeNode* node, long targetSum) {
        if (node == nullptr) return 0;
        return (node->val == targetSum ? 1 : 0) + 
               pathSumFrom(node->left, targetSum - node->val) + 
               pathSumFrom(node->right, targetSum - node->val);
    }
    int pathSum(TreeNode* root, long targetSum) {
        if (root == nullptr) return 0;
        return pathSumFrom(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};

int main() {
    TreeNode* root = new TreeNode(10, new TreeNode(5, new TreeNode(3, new TreeNode(3), new TreeNode(-2)), new TreeNode(2, nullptr, new TreeNode(1))), new TreeNode(-3, nullptr, new TreeNode(11)));
    int targetSum = 8;
    cout << Solution().pathSum(root, targetSum) << endl;
}