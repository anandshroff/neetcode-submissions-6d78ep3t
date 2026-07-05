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
    TreeNode* decode(vector<string>&nodes, int &idx){
        
        if(nodes[idx] == "#"){
            idx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[idx]));
        idx++;
        root->left = decode(nodes, idx);
        root->right = decode(nodes, idx);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        encode(root, str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string str = "";
        vector<string>nodes;

        for(auto &c: data){
            if(c == ','){
                nodes.push_back(str);
                str.clear();
            }
            else{
                str = str + c;
            }
        }
        int idx = 0;
        return decode(nodes, idx);
    }
};
