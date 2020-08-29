#include<bits/stdc++.h>
using namespace std;
void initialize(vector<int> &parents)
{

    for(int i = 0 ; i  < parents.size() ; i++)
    {
        parents[i] = i;
    }
}
int findparent(int x, vector<int> &parents)
{
    if(parents[x] == x)
    {
        return x;
    }
    int temp = findparent(parents[x], parents);
    parents[x] = temp;
    return temp;
}
void union_vertices(int x, int y, vector<int> &parents, vector<int> &ranks)
{
    int parx = findparent(x,parents);
    int pary = findparent(y,parents);

    if(parx != pary)
    {
        if(ranks[parx] < ranks[pary])
        {
            parents[parx] = pary;
        }
        else if(ranks[parx] > ranks[pary])
        {
            parents[pary] = parx;
        }
        else
        {
            parents[parx] = pary;
            ranks[pary]++;
        }
    }
}
bool isvalid(vector<vector<int>> &graph, int m , int n)
{
    if(m < 0 || n < 0 || m >= graph.size() || n >= graph[0].size() || !graph[m][n])
    {
        return false;
    }
    return true;
}
void evaluate(int x, int y, vector<int> &parents, vector<int> &ranks, int &counter, vector<vector<int>> &graph)
{

        counter++;
        int currcell = x*graph[0].size() + y;
        graph[x][y] = 1;
        vector<vector<int>> dir{{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(int i = 0 ; i < dir.size() ; i++)
        {
            int cordx = x + dir[i][0] , cordy = y  + dir[i][1];
            if(isvalid(graph , cordx, cordy))
            {
                int eqcell = cordx * graph[0].size() + cordy;
                int p1 = findparent(currcell, parents);
                int p2 = findparent(eqcell, parents);
                if(p1!=p2)
                {
                    union_vertices(currcell, eqcell, parents, ranks);
                    counter--;
                }
            }
        }
}

int main()
{

    int m, n;
    cin>>m>>n;
    vector<int> parents(m*n);
    vector<int> ranks(m*n , 1);
    vector<vector<int>> graph(m, vector<int>(n,0));
    initialize(parents);
    int k;
    cin>>k;
    int counter = 0;

    for(int i =0 ; i  < k  ; i++)
    {
        int x, y;
        cin>> x>>y;
        evaluate( x,  y, parents, ranks, counter, graph);
        cout<<counter << endl;
    }

}
