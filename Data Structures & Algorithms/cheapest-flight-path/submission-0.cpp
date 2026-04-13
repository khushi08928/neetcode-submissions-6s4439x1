class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        for(auto& it:flights){
            adjList[it[0]].push_back({it[1],it[2]});
        }
        vector<vector<int>>prices(n,vector<int>(k+2,INT_MAX));
        prices[src][0]=0;
        queue<pair<int,pair<int,int>>>que;
        que.push({0,{src,0}}); // {stops,{node,cost}};
        while(!que.empty() && que.front().first<=k){
            int stops=que.front().first;
            int node=que.front().second.first;
            int cost=que.front().second.second;
            que.pop();
            if(stops>k) continue;
            for(auto& neigh:adjList[node]){
                int adjNode=neigh.first;
                int price=neigh.second;
                if(cost+price<prices[adjNode][stops+1]){
                    prices[adjNode][stops+1]=cost+price;
                    que.push({stops+1,{adjNode,cost+price}});
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<=k+1;i++){
            ans=min(ans,prices[dst][i]);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
