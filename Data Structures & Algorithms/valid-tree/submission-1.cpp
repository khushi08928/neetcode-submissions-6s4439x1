class Solution {
private:
    bool checkCycle(int i,int par,vector<bool>& vis,vector<vector<int>>& adjlist){
        vis[i]=true;
        for(int j:adjlist[i]){
            if(!vis[j]){
                if(checkCycle(j,i,vis,adjlist)){
                    return true;
                }
            }else if(j!=par){
                return true;
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<bool>vis(n,false);
        vector<vector<int>> adjlist(n);
        for(auto& edge:edges){
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(checkCycle(i,-1,vis,adjlist)){
                    return false;
                }
            }
        }
        return true;
    }
};
