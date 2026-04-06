class Solution {
private:
    void dfs(int n,int m,vector<vector<bool>>&vis,vector<vector<char>>&grid,int i,int j){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j]!='1'){
            return;
        }
        vis[i][j]=true;
        dfs(n,m,vis,grid,i-1,j);
        dfs(n,m,vis,grid,i,j+1);
        dfs(n,m,vis,grid,i+1,j);
        dfs(n,m,vis,grid,i,j-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int islands=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(n,m,vis,grid,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
