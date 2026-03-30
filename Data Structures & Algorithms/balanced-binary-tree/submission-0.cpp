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
    bool isbalanced=true;
    int checkheight(TreeNode* root){
        if(root==NULL) return 0;

        int leftHeight=checkheight(root->left);
        int rightHeight=checkheight(root->right);

        if(abs(leftHeight-rightHeight)>1) isbalanced=false;

        return 1+max(leftHeight,rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        checkheight(root);
        return isbalanced;
    }
};
