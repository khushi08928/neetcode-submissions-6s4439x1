class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>>cars;
        stack<double>st;
        for(int i=0;i<n;i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end(),greater<pair<int,int>>());
        for(auto& it:cars){
            double position=it.first;
            double speed=it.second;
            double time=(target-position)/speed;
            if(st.empty()) st.push(time);
            if(st.top()>=time) continue;
            if(st.top()<time) st.push(time);
        }
        return st.size();
    }
};
