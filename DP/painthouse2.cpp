    #include<bits/stdc++.h>
    using namespace std;
    int painthousetwo(vector<vector<int>>& costs)
    {
        int previosmin, previoussmin, currmin, currsecondmin;
        vector<vector<int>> dp(costs.size() , vector<int>(costs[0].size(),0));
        for(int i = 0 ; i  < costs.size() ; i++)
        {
            currmin = INT_MAX , currmin = INT_MAX;
            for(int j =0 ; j < costs[0].size() ; j++)
            {
                    if(i == 0)
                    {
                        dp[i][j] = costs[i][j];
                        if(dp[i][j] < currmin)
                        {
                            currsecondmin = currmin;
                            currmin = dp[i][j];
                        }
                        else
                        {
                            currsecondmin = min(dp[i][j], currsecondmin);
                        }
                        //update currman and min
                        continue;
                    }

                    if(previosmin == dp[i-1][j])
                    {
                        dp[i][j] = previosmin;
                    }
                    else
                    {
                        dp[i][j] = previosmin;
                    }
                    dp[i][j] += costs[i][j];
                    if(dp[i][j] < currmin)
                    {
                        currsecondmin = currmin;
                        currmin = dp[i][j];
                    }
                    else
                    {
                        currsecondmin = min(dp[i][j], currsecondmin);
                    }

            }
            previosmin = currmin;
            previoussmin = currsecondmin;

        }

        return min(previosmin, previosmin);
    }
    int main()
    {
        vector<vector<int>> costs{{14,2,11},{11,14,5},{14,3,10}};

        cout<<painthousetwo(costs);

    }
