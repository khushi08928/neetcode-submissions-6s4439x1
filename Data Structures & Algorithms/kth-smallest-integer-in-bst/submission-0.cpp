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
    void inOrder(TreeNode* root ,int k, int &ans,int &count){
        if(root==NULL) return;
        inOrder(root->left,k,ans,count);
        cout<<"root val is : "<<root->val<<" ";
        count++;
        if(count==k){
            ans=root->val;
            return;
        }
        inOrder(root->right,k,ans,count);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        int count=0;
        inOrder(root,k,ans,count);
        return ans;
    }
};
