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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, ans);
        return ans[k - 1]; // Convert 1-based 'k' to 0-based array index
    }

private:
    void inorder(TreeNode* node, vector<int>& ans) {
        if (node == nullptr) return;
        
        inorder(node->left, ans);      // 1. Go completely left
        ans.push_back(node->val);      // 2. Process the root (add to array)
        inorder(node->right, ans);     // 3. Go right
    }
};