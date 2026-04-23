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
    int maxSum(TreeNode* root, int &maxS){
        if(!root)
            return 0;
        
        int L = max(0, maxSum(root->left, maxS));
        int R = max(0, maxSum(root->right, maxS));

        maxS = max(maxS, L+R+root->val);

        return max(L,R) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxS = INT_MIN;
        maxSum(root, maxS);
        return maxS;
    }
};
