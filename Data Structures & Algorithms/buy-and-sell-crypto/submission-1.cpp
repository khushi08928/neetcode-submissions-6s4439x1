class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int n=prices.size();
        int left = 0;
        int right = 1;
        while(right<n){
            if(prices[right]>prices[left]){
                int cost = prices[right]-prices[left];
                maxprofit=max(maxprofit,cost);
            }else{
                left=right;
            }
            right++;
        }
        return maxprofit;
    }
};
