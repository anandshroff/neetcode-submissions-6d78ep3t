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
    int g = 0;
    void findMax(TreeNode* root, int maxi){
        if(!root) return;
        if(root->val >= maxi){ 
            g++;
            maxi = root->val;
        }

        findMax(root->left, maxi);
        findMax(root->right, maxi);

    }
public:
    int goodNodes(TreeNode* root) {
        findMax(root, INT_MIN);
        return g;
    }
};
