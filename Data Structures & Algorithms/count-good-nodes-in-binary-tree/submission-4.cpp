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
    void findGood(TreeNode* root, int &cnt, int max){
        if(!root) return;

        if(root->val >= max){
            cnt++;
            max = root->val;
        }
        findGood(root->left, cnt, max);
        findGood(root->right, cnt, max);
    }
public:
    int goodNodes(TreeNode* root) {
        
        int cnt = 0;
        findGood(root, cnt, INT_MIN);
        return cnt;
    }
};
