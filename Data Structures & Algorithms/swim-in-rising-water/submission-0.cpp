class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int directions[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > minheap;
        minheap.push({grid[0][0],{0,0}});
        vis[0][0]=true;
        while(!minheap.empty()){
            int time=minheap.top().first;
            int row=minheap.top().second.first;
            int col=minheap.top().second.second;
            minheap.pop();
            vis[row][col]=true;
            if(row==n-1 && col==n-1) return time;
            for(int i=0;i<4;i++){
                int neighrow=row+directions[i][1];
                int neighcol=col+directions[i][0];
                if(neighrow>=n || neighcol>=n || neighrow<0 || neighcol<0 || vis[neighrow][neighcol]){
                    continue;
                }
                vis[neighrow][neighcol]=true;
                minheap.push({max(time,grid[neighrow][neighcol]),{neighrow,neighcol}});
            }
        }
        return -1;
    }
};
