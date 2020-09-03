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
pair<int,int> schedule(vector<task> &tasks, int maxdeadline)
{
    pair<int,int> ans;
    vector<bool> vis(maxdeadline, false);
    vis[0] = true;
    sort(tasks.begin(), tasks.end(),mycomp);
    int counter = 0;
    int p = 0;
     for(task task1 : tasks)
    {
        cout<<task1.id <<" " <<task1.deadline<<" " << task1.profit<< endl;
    }
    cout<<"next loop"<<endl;
    for(task task1 : tasks)
    {
        cout<<task1.id <<" " <<task1.deadline<<" " << task1.profit<< " ";
        int d = task1.deadline;
        for(int j = d ; j >= 0 ; j-- )
        {
            if(!vis[j])
            {
                vis[j] = true;
                counter++;
                p+= task1.profit;
                cout<<"taken ";
                break;
            }
        }
        cout<<endl;
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
