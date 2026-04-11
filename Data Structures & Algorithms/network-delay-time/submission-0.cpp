class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adjList(n+1);
        for(auto& it:times){
            adjList[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
        vector<int>timetoReach(n+1,INT_MAX);
        timetoReach[k]=0;
        minheap.push({0,k});
        while(!minheap.empty()){
            int time=minheap.top().first;
            int node=minheap.top().second;
            minheap.pop();
            for(auto& neighbours:adjList[node]){
                int neighNode=neighbours.first;
                int currtime=neighbours.second;
                if(time+currtime<timetoReach[neighNode]){
                    timetoReach[neighNode]=time+currtime;
                    minheap.push({timetoReach[neighNode],neighNode});
                }
            }
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            if(timetoReach[i]==INT_MAX) return -1;
            ans=max(ans,timetoReach[i]);
        }
        return ans;
    }
};
