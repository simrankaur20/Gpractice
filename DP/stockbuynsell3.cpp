class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxsofar(prices.size(),0);
        int profit = 0;
        int max_from_right = prices[prices.size()-1];
        int maxprofit = 0;

        for(int i = prices.size() - 2 ; i >=0 ; i--)
        {
            max_from_right = max(max_from_right, prices[i]);
            maxsofar[i] = max(maxsofar[i+1] , max_from_right - prices[i]);
        }
        int minsofar = INT_MAX;
         profit = 0;
        int max_ = 0;
        for(int i = 0 ; i < prices.size() ; i++)
        {
            minsofar = min(prices[i] , minsofar);
            if(i!=0)
            {
              int currentprofit = prices[i] - minsofar;
              profit = max(profit, currentprofit);
                maxsofar[i] += profit;
            }
         max_ = max(max_ , maxsofar[i]);
        }
        return max_;
    }
};
