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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> output = {};

        bool notFinishedLevel = true;

        queue<TreeNode*> lastNodes = {};
        queue<TreeNode*> currentNodes = {};
        TreeNode* node;

        vector<int> tempOutput;

        currentNodes.push(root);
        while (notFinishedLevel) {
            lastNodes = currentNodes;
            currentNodes = {};


            notFinishedLevel = false;
            tempOutput = {};

            // we start a new level, we need the previous node to compute the next ones


            while (!lastNodes.empty()) {
                node = lastNodes.front();
                lastNodes.pop();
                tempOutput.push_back(node->val);

                if (node->left != nullptr) {
                    currentNodes.push(node->left);
                    notFinishedLevel = true;
                }

                if (node->right != nullptr) {
                    currentNodes.push(node->right);
                    notFinishedLevel = true;
                }



            }

            output.push_back(tempOutput);
             
        }

        return output;
        
    }
};
