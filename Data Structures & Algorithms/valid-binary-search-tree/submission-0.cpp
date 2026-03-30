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
    bool dfs(TreeNode* root,long minval,long maxval){
        if(root==NULL) return true;
        if(root->val<=minval || root->val>=maxval){
            return false;
        }
        bool leftcheck=dfs(root->left,minval,root->val);
        if(leftcheck==false) return false;
        bool rightcheck=dfs(root->right,root->val,maxval);
        return rightcheck;
    }
public:
    bool isValidBST(TreeNode* root) {
        bool result=dfs(root,LONG_MIN,LONG_MAX);
        return result;
    }
};
