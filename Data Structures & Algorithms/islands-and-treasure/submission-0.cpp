class Solution {
private:
    void addroom(int row,int col,int n,int m,vector<vector<bool>>&vis,vector<vector<int>>&grid,queue<pair<int,int>>&que){
        if(row<0 || col<0 || row>=n || col>=m || vis[row][col] || grid[row][col]==-1){
            return;
        }
        vis[row][col]=true;
        que.push({row,col});
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>que;
        int distance=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    que.push({i,j});
                    vis[i][j]=true;
                }
            }
        }
        while(que.size()>0){
            int quesize=que.size();
            for(int i=0;i<quesize;i++){
                int row=que.front().first;
                int col=que.front().second;
                que.pop();
                if(grid[row][col] == 2147483647){
                    grid[row][col] = distance;
                }
                addroom(row+1,col,n,m,vis,grid,que);
                addroom(row-1,col,n,m,vis,grid,que);
                addroom(row,col-1,n,m,vis,grid,que);
                addroom(row,col+1,n,m,vis,grid,que);
            }
            distance+=1;
        }
    }
};
