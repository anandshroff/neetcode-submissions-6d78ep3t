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

    int dfs(TreeNode* node, int &res)
    {
        if(node == nullptr)
            return 0;

        int h1 = dfs(node->left, res);
        int h2 = dfs(node->right, res);
        res = max(res, h1+h2);
        return max(h1,h2) + 1;  

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        dfs(root, res);
        return res;

    }
};
