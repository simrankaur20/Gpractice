class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int bp = INT_MAX , sp = INT_MIN;
        for(int i = 0; i < prices.size()   ; )
        {
            // cout<<bp<<" "<<sp<<endl;
            if(sp != INT_MIN && prices[i] < sp)
            {
                profit += (sp-bp);
                bp = INT_MAX;
                sp=INT_MIN;
                continue;
            }
            if(prices[i] <= bp)
            {
                bp = prices[i];
                i++;
                continue;
            }
            if(bp != INT_MIN && prices[i] >= sp)
            {
                sp = prices[i];
                i++;
            }
        }
        if( sp != INT_MIN)
        {
            profit += (sp-bp);
        }
        return profit;

    }
};
