class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            int curr=asteroids[i];
            if(st.empty()){
                st.push(curr);
            }
            else if(st.top()>0 && curr>0){
                st.push(curr);
            }
            else if(st.top()>0 && curr<0){
                while(!st.empty() && st.top()>0 && curr<0){
                    if(abs(st.top())<abs(curr)){
                        st.pop();
                        continue;
                    }
                    else if(abs(st.top())>abs(curr)){
                        curr=0;
                        break;
                    }
                    else{
                        st.pop();
                        curr=0;
                        break;
                    }
                }
                if(curr!=0){
                    st.push(curr);
                }
            }
            else{
                st.push(curr);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};