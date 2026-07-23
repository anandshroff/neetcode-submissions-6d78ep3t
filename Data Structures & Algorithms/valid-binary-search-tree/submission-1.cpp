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
    bool validate(TreeNode* root, int left, int right){
        if(!root) return true;

        if(left < root->val && right > root->val){
            if(validate(root->left, left, root->val) && 
            validate(root->right, root->val, right))
                return true;
        }

        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(validate(root, INT_MIN, INT_MAX))
            return true;
        
        return false;
    }
};
