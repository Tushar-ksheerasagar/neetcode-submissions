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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root,out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }
private:
    void serializeHelper(TreeNode * node,ostringstream &out){
        if(!node){
            out << "# ";
            return;
        }
        out << node->val << " ";
        serializeHelper(node->left,out);
        serializeHelper(node->right,out);
    }
    TreeNode * deserializeHelper(istringstream &in){
        string val;
        in >> val;
        if(val == "#" || val.empty()) return nullptr;
        TreeNode * node = new TreeNode(stoi(val));
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        return node;
    }
};
