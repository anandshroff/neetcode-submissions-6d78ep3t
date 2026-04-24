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
    void traverse(TreeNode* root, int &res, int maxi)
    {
        if(!root) return;

        if(root->val >= maxi){
            maxi = root->val;
            res++;
        }
        traverse(root->left, res, maxi);
        traverse(root->right, res, maxi);
    }
    int goodNodes(TreeNode* root) {
        int res = 0;

        traverse(root, res, INT_MIN);
        return res;
    }
};
