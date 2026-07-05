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

class Codec {
    void encode(TreeNode* root, string &str){
        if(!root){
            str = str + "#,";
            return;
        }
        str = str + to_string(root->val) + ",";
        encode(root->left, str);
        encode(root->right, str);
    }
    TreeNode* decode(stringstream &str){
        string val;
        getline(str, val, ',');

        if(val == "#")
            return nullptr;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = decode(str);
        node->right = decode(str);
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        encode(root, str);
        cout<<str;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return decode(ss);
    }
};
