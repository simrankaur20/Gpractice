#include<bits/stdc++.h>
using namespace std;
pair<int,int> getrowno(int r)
{
    if(r == 0)
        return make_pair(r+1, r+2);
    else if(r == 1)
        return make_pair(0,2);
    else
        return make_pair(0,1);
}
int mincostofpainting(vector<vector<int>> &costs)
{
    vector<vector<int>> dp(3,vector<int>(costs[0].size() , 0));

    for(int j = 0; j < 3; j++)
    {
        for(int i = 0 ; i  < costs.size() ; i++)
        {
            if(j == 0)
            {
                dp[i][j] = costs[j][i];
            }
            else
            {
                pair<int,int> row = getrowno(i);
                int col = j-1;
                dp[i][j] = min(dp[row.first][col] , dp[row.second][col]) + costs[j][i];
            }
        }
    }
    for(vector<int> &x : dp)
    {
        for(int i : x)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return min(dp[0][dp.size() - 1], min(dp[1][dp.size()-1], dp[2][dp.size()-1]));
}
int main()
{
    vector<vector<int>> costs{{14,2,11},{11,14,5},{14,3,10}};
    cout<<mincostofpainting(costs);
}
