class Solution {
private:
    int dfs(int n,int m,vector<vector<bool>>&vis,vector<vector<int>>&grid,int i,int j){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j]!=1){
            return 0;
        }
        int area=1;
        vis[i][j]=true;
        area+=dfs(n,m,vis,grid,i-1,j);
        area+=dfs(n,m,vis,grid,i,j+1);
        area+=dfs(n,m,vis,grid,i+1,j);
        area+=dfs(n,m,vis,grid,i,j-1);
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxArea=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int ans = dfs(n,m,vis,grid,i,j);
                    maxArea=max(ans,maxArea);
                }
            }
        }
        return maxArea;
    }
};
