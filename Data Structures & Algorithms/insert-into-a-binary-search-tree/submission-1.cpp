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
private:
    void insert(TreeNode* root, int val){
        if(!root->left && root->val > val){
        TreeNode* node = new TreeNode(val);
        root->left = node;
        } 
        if(!root->right && root->val < val){
            TreeNode* node = new TreeNode(val);
            root->right = node;
        }
    

        if(root->val > val)
            insert(root->left, val);
        if(root->val < val)
            insert(root->right, val);
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        insert(root, val);

        return root;
    }
};