class Solution {
private:
    int dfs(vector<vector<int>>& adjList, vector<bool>& hasApple, int node, int parent) {
        int total=0;
        for(auto& childnode:adjList[node]){
            if(childnode==parent) continue;
            int childnodeTime=dfs(adjList,hasApple,childnode,node);
            if(childnodeTime>0 || hasApple[childnode]){
                total+=childnodeTime+2;
            }
        }
        return total;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adjList(n);
        for(auto& it:edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        int ans=dfs(adjList,hasApple,0,-1);
        return ans;
    }
};