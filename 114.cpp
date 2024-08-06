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
    // void flatten(TreeNode* root) {
    //     if (root == nullptr) return;
    //     stack<TreeNode*> stk;
    //     stk.push(root);
    //     TreeNode* pre = nullptr;
    //     while (!stk.empty()) {
    //         TreeNode* tmp = stk.top();
    //         stk.pop();
    //         if (pre != nullptr) {
    //             pre->right = tmp;
    //             pre->left = nullptr;
    //         }
    //         if (tmp->right != nullptr) stk.push(tmp->right);
    //         if (tmp->left != nullptr) stk.push(tmp->left);
    //         pre = tmp;
    //     }
    // }
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left) {
                TreeNode* rightest = root->left;
                while (rightest->right) rightest = rightest->right;
                rightest->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};

void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
        else cout << "null ";
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5, nullptr, new TreeNode(6)));
    Solution().flatten(root);
    printTree(root);
}