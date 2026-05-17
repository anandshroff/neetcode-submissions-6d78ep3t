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
    void serialize(TreeNode* root, string &str){
        if(!root){
            str += "#,";
            return;
        }
        str += to_string(root->val) + ",";
        serialize(root->left, str);
        serialize(root->right, str);
        
    }
   
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string str1 = "";
        string str2 = "";

        serialize(root, str1);
        serialize(subRoot, str2);

        return (str1.find(str2) != string::npos);
    }
};
