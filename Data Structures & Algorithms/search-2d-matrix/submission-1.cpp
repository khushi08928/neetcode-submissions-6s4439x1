class Solution {
private:
    bool dfs(int i,int j,vector<vector<int>>& matrix,vector<vector<bool>>& vis,int target,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==true){
            return false;
        }
        vis[i][j]=true;
        if(matrix[i][j]==target){
            return true;
        }
        if(dfs(i+1,j,matrix,vis,target,n,m)) return true;
        if(dfs(i-1,j,matrix,vis,target,n,m)) return true;
        if(dfs(i,j+1,matrix,vis,target,n,m)) return true;
        if(dfs(i,j-1,matrix,vis,target,n,m)) return true;
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<bool>>vis(n,vector<bool>(m,false));
                if(dfs(i,j,matrix,vis,target,n,m)){
                    return true;
                }
            }
        }
        return false;
    }
};
