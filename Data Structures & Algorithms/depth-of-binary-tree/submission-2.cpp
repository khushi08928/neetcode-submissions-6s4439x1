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
    int maxDepth(TreeNode* root) {
        int countdepth=0;
        if(root==NULL) return countdepth;
        int leftdepth=maxDepth(root->left);
        int rightdepth=maxDepth(root->right);
        countdepth=1+max(leftdepth,rightdepth);
        return countdepth;
    }
};
