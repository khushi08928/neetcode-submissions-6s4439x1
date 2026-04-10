class Solution {
private:
    bool dfs(int row,int col,vector<vector<int>>&matrix,int target,vector<vector<bool>>&vis,int n,int m){
        if(row<0 || col<0 || row>=n || col>=m || vis[row][col]==true){
            return false;
        }
        vis[row][col]=true;
        if(matrix[row][col]==target){
            return true;
        }
        if(dfs(row+1,col,matrix,target,vis,n,m)) return true;
        if(dfs(row-1,col,matrix,target,vis,n,m)) return true;
        if(dfs(row,col+1,matrix,target,vis,n,m)) return true;
        if(dfs(row,col-1,matrix,target,vis,n,m)) return true;
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<bool>>vis(n,vector<bool>(m,false));
                if(dfs(i,j,matrix,target,vis,n,m)) return true;
            }
        }
        return false;
    }
};
