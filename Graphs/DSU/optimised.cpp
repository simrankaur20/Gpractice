//path compression and union by rank
#include<bits/stdc++.h>
using namespace std;
void initialize(vector<int> &parents)
{
    for(int i = 0 ; i < parents.size() ; i++)
    {
        parents[i] = i;
    }
}

int findparent(int x, vector<int> &parent)
{
    if(parent[x] == x)
    {
        return x;
    }
    int temp = findparent(parent[x], parent);
    parent[x] = temp;
    return temp;
}

void union_vertices(int x, int y, vector<int> &parents, vector<int> &ranks)
{
    int par1 = findparent(x,parents);
    int par2 = findparent(y,parents);
    if(par1 != par2)
    {
        if(ranks[par1] > ranks[par2])
        {
            parents[par2] = par1;
        }
        else if(ranks[par1] < ranks[par2])
        {
            parents[par1] = par2;
        }
    }
    else
    {
        parents[par1] = par2;
        ranks[par2]++;
    }
}
int main()
{
   vector<int> parents(7 , 0);
   vector<int> ranks(7,1);
   initialize(parents);
   cout<<findparent(1,parents)<<endl;
   union_vertices(2,3, parents, ranks);
   cout<<findparent(2,parents)<<endl;

}
