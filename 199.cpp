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
    void helper(TreeNode* r, int l) {
        if (r == nullptr) return;
        if (l > res.size()) res.push_back(r->val);
        if (r->right) helper(r->right, l + 1);
        if (r->left) helper(r->left, l + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        helper(root, 1);
        return res;
    }
};

int main() {
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->right = new TreeNode(5);
    head->right->right = new TreeNode(4);
    vector<int> res = Solution().rightSideView(head);
    for (auto n :  res) cout << n << ' ';
}