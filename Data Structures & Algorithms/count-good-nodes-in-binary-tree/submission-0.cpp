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
    void countgoodnode(TreeNode* root, int maxel){
        if(root==NULL) return;
        if(root->val>=maxel){
            goodnode++;
        }
        int newmax=max(maxel,root->val);
        countgoodnode(root->left,newmax);
        countgoodnode(root->right,newmax);
    }
public:
    int goodnode=0;
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        countgoodnode(root,root->val);
        return goodnode;
    }
};
