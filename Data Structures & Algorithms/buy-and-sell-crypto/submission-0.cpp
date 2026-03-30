class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int n=prices.size();
        int mini=prices[0];
        for(int i=1;i<n;i++){
            int profit = prices[i]-mini;
            maxprofit=max(profit,maxprofit);
            mini=min(prices[i],mini);
        }
        return maxprofit;
    }
};
