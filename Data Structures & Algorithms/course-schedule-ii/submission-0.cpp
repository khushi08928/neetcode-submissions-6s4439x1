class Solution {
public:
    bool dfs(int src,vector<bool>& vis ,vector<bool>& recPath,vector<vector<int>>& prerequisites){
        vis[src]=true;
        recPath[src]=true;
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            int v=prerequisites[i][0];
            int u=prerequisites[i][1];

            if(u==src){
                if(!vis[v]){
                    if(dfs(v,vis,recPath,prerequisites)){
                        return true;
                    }
                }else if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false;
    }

    void topologicalsort(int src,vector<bool>&vis , stack<int>&st,vector<vector<int>>& prerequisites){
        vis[src]=true;
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            int v=prerequisites[i][0];
            int u=prerequisites[i][1];

            if(u==src){
                if(!vis[v]){
                    topologicalsort(v,vis,st,prerequisites);
                }
            }
        }
        st.push(src);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>result;
        stack<int>st;
        vector<bool>vis(numCourses,false);
        vector<bool>recPath(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,recPath,prerequisites)){
                    return result;
                }
            }
        }

        vis.assign(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                topologicalsort(i,vis,st,prerequisites);
            }
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};
