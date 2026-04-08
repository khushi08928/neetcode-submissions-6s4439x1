class Solution {
public:
    vector<int>parent,rank;

    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u=parent[u];
        int ulp_v=parent[v];
        if(ulp_u==ulp_v) return;
        if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];

            if(findUPar(u)==findUPar(v)){
                return edge;
            }

            unionByRank(u,v);
        }
        return {};
    }
};
