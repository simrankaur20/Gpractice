#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class task{
  public :
  int id, deadline, profit;
  task(int id,int deadline,int profit)
  {
      this->id = id;
      this->deadline = deadline;
      this->profit = profit;
  }
};
bool mycomp(task &t1, task &t2)
{
    return t1.profit > t2.profit;
}

class DSU{
public :
    vector<int> parents;
    DSU(int n)
    {
        for(int i = 0 ; i  < n ; i++)
        {
            parents.push_back(i);
        }
    }


    int find(int x)
    {

        if(parents[x] == x)
        {
            return x;
        }
        int temp = find(parents[x]);
        parents[x] = temp;
        return temp;
    }

    void union_vertices(int x, int y)
    {
        int p1 = find(x);
        int p2 = find(y);
        if(p1!= p2)
        {
            parents[p1] = p2;
        }
    }
};
pair<int,int> schedule(vector<task> &tasks, int maxdeadline)
{
    pair<int,int> ans;
    DSU dsu(maxdeadline + 1);
    sort(tasks.begin(), tasks.end(),mycomp);
    int counter = 0;
    int p = 0;
    for(task task1 : tasks)
    {
        int d = task1.deadline;

        int p1 = dsu.find(d);
        if(p1 == 0) continue;

        dsu.union_vertices(p1,p1-1);
        counter++;
        p+= task1.profit;
    }
    return make_pair(counter, p);
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<task> tasks;
	    int maxdeadline = 0;
	    for(int i = 0; i < n ; i++)
	    {
	        int x,y,z;
	        cin>>x>>y>>z;
	        maxdeadline = max(y, maxdeadline);
	        tasks.push_back(task(x,y,z));
	    }
	    pair<int, int> ans =  schedule(tasks, maxdeadline);
	    cout<<ans.first<<" " << ans.second<<endl;
	}
	return 0;
}
