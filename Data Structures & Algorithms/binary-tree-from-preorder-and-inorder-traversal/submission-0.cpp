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
    unordered_map<int, int>mp;
    int preIdx = 0;
    TreeNode* build(vector<int>&preorder, int left, int right){
        if(left > right)
            return nullptr;
        
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int idx = mp[rootVal];

        root->left = build(preorder, left, idx-1);
        root->right = build(preorder, idx+1, right);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size();i++)
            mp[inorder[i]] = i;

            return build(preorder, 0, preorder.size()-1);
           
        }
};
