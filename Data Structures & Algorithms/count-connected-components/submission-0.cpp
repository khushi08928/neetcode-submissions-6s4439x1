class Solution {
public:
    vector<int>size,parent;
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }

    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int res=n;
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            if(findUPar(u)!=findUPar(v)){
                unionBySize(u,v);
                res--;
            }
        }
        return res;
    }
};
