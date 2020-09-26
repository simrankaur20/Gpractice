#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool existseulerian(vector<vector<int>> &g)
{
    vector<int> degree(g.size() , 0);

    for(int i = 0 ; i < g.size() ; i++)
    {
        for(int j = 0 ; j  <  g[0].size() ; j++)
        {
            if(g[i][j])
            {
                degree[i]++;
            }
        }
    }

    int e = 0 , o = 0;
    for(int x : degree)
    {
        if(x % 2 == 0 ) e++;
        else o++;
    }
    return o == 2 || o == 0;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<vector<int>> g(n, vector<int>(n,0));

	    for(int i = 0 ; i < g.size() ; i++)
	    {
	        for(int j = 0 ; j  < g[0].size() ; j++)
	        {
	            cin>>g[i][j];
	        }
	    }
	    cout<<existseulerian(g)<<endl;
	}

	return 0;
}
