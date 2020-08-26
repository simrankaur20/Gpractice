class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int maxsofar = prices[prices.size()-1], profit = INT_MIN;

        for(int i = prices.size()-2; i>=0 ; i--)
        {
            int currentprofit = maxsofar - prices[i]  ;
            maxsofar = max(maxsofar,prices[i]);
            profit= max(profit, currentprofit);
        }
        return max(profit, 0);
    }
};
