class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        int maxarea=INT_MIN;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int height=heights[st.top()];
                st.pop();
                int right=i;
                int left;
                if(st.empty()){
                    left=-1;
                }else{
                    left=st.top();
                }
                int width=right-left-1;
                int currarea=height*width;
                maxarea=max(maxarea,currarea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int height=heights[st.top()];
            st.pop();
            int right=n;
            int left;
            if(st.empty()){
                left=-1;
            }else{
                left=st.top();
            }
            int width=right-left-1;
            int currarea=width*height;
            maxarea=max(currarea,maxarea);
        }
        return maxarea;
    }
};
