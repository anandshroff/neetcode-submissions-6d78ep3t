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
    bool validate(TreeNode* root, int minV, int maxV)
    {
        if(!root) return true;

        if(root->val > minV && root->val < maxV){
            
            return validate(root->left, minV, root->val) &&
                   validate(root->right, root->val, maxV);
        }
        
        return false;
        
    }
    bool isValidBST(TreeNode* root) {
        if(validate(root, INT_MIN, INT_MAX))
            return true;
        
        return false;
    }
};
