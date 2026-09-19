/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



int computeDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int val = std::max(computeDepth(root->left),computeDepth(root->right));
    root->val = val;
    return 1 + val;
}


int findMaxDiff(TreeNode* root) {
    if (root == nullptr) return 0;
    int l = 0;
    if (root->left != nullptr) l = 1 + root->left->val;
    int r = 0;
    if (root->right != nullptr) r = 1 + root->right->val;

    return max(l + r, max(findMaxDiff(root->left),findMaxDiff(root->right)));
}




class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        computeDepth(root);
        return findMaxDiff(root);

        
    }
};



