class Solution {
private:
    void dfs(int row, int col, vector<vector<bool>>& visit,vector<vector<int>>& heights, int n, int m, int prevHeight) {
        if(row < 0 || col < 0 || row >= n || col >= m)
            return;
        
        if(visit[row][col] || heights[row][col] < prevHeight)
            return;

        visit[row][col] = true;

        dfs(row+1,col,visit,heights,n,m,heights[row][col]);
        dfs(row-1,col,visit,heights,n,m,heights[row][col]);
        dfs(row,col+1,visit,heights,n,m,heights[row][col]);
        dfs(row,col-1,visit,heights,n,m,heights[row][col]);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        vector<vector<bool>>atlantic(n,vector<bool>(m,false));
        for(int i=0;i<m;i++){
            //for top row
            dfs(0,i,pacific,heights,n,m,heights[0][i]);
            //for bottom row
            dfs(n-1,i,atlantic,heights,n,m,heights[n-1][i]);
        }

        for(int i=0;i<n;i++){
            //for left column
            dfs(i,0,pacific,heights,n,m,heights[i][0]);
            //for right column
            dfs(i,m-1,atlantic,heights,n,m,heights[i][m-1]);
        }

        vector<vector<int>>result;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};
