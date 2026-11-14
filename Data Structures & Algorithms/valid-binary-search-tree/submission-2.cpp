bool valid(TreeNode* root, int down, int up) {
    //cout << "\n\ndown = " << down << "\n";
    //cout << "root->val = " << root->val << "\n";
    //cout << "up = " << up << "\n";

    //cout << down << " " << root->val << " " << up << "\n";
    //cout << "down > root->val || root->val > up = " << bool(down > root->val || root->val > up) << "\n"; 
    if (down >= root->val || root->val >= up) return false;
    bool l = true;
    bool r = true;

    if (root->left != nullptr) l = valid(root->left, down, root->val);
    if (l == false) return false;
    if (root->right != nullptr) r = valid(root->right, root->val, up);
    if (r == false) return false;
    //cout << "l = " << l << "\n";
    //cout << "r = " << r << "\n";
    return (l && r);
}



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

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        //cout << "root->val = " << root->val << "\n";
        
        bool l = true;
        bool r = true;
        if (root->left != nullptr) l = valid(root->left, INT_MIN, root->val);
        if (root->right != nullptr) r = valid(root->right, root->val, INT_MAX);
        return (l && r);
    }
};
