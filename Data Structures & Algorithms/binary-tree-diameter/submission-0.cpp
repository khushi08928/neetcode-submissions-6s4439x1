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
    int treediameter(TreeNode* root){
        if(root==NULL) return 0;
        int left=treediameter(root->left);
        int right=treediameter(root->right);
        diameter=max(diameter,left+right);
        int height=1+max(left,right);
        return height;
    }
public:
    int diameter=0;
    int diameterOfBinaryTree(TreeNode* root) {
        treediameter(root);
        return diameter;
    }
};
