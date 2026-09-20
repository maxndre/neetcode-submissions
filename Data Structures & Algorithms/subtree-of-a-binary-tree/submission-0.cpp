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


 
bool isSameTree(TreeNode* p, TreeNode* q) {

    if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) return false;
    if (p == nullptr) return true;
    if (p->val != q->val) return false;

    return isSameTree(p->right ,q->right) && isSameTree(p->left ,q->left);
    
}

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (subRoot == nullptr) return true;

        if (root == nullptr) return false;

        // both pointers are not null

        if (root->val == subRoot->val && isSameTree(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }
};


