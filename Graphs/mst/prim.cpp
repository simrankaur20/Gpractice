#include<bits/stdc++.h>
using namespace std;
class Edge{
public :
    int v, wt;
    Edge(int v, int weight)
    {

        this->v = v;
        wt = weight;
    }
};
vector<vector<Edge>> g(9, vector<Edge>());

void addEdge(int u, int v, int w)
{
    g[u].push_back(Edge(v,w));
    g[v].push_back(Edge(u,u));
}
class Primpair{
public:
    int u, par,wt;
    Primpair(int u, int par, int wt)
    {
        this->u = u;
        this->par = par;
        this->wt = wt;
    }
};
class mycomp{
public:
    int operator()(const Primpair &p1, const Primpair &p2)
    {
        return p1.wt > p2.wt;
    }
};
int Prim(int src, int v)
{

    priority_queue<Primpair, vector<Primpair>, mycomp> pq;
    pq.push(Primpair(src, -1 , 0));
    vector<bool> vis(v,false);
    int count = 0;int ans = 0;
    vector<vector<Edge>> mstset(9 , vector<Edge>());
    while(count != v-1)
    {

        Primpair e = pq.top();
        pq.pop();
        if(vis[e.u])
            continue;
        if(e.par != -1)
        {
            mstset[e.par].push_back(Edge(e.u , e.wt));
            mstset[e.u].push_back(Edge(e.par , e.wt));
            ans += e.wt;
            count++;
        }
        vis[e.u] = true;

        for(Edge curr : g[e.u])
        {
            if(!vis[curr.v])
            {
                pq.push(Primpair(curr.v, e.u, curr.wt));
            }
        }
    }

    return ans;
}
int main()
{

        addEdge(0, 1, 4);
        addEdge(0, 7, 8);
        addEdge(1, 2, 8);
        addEdge(1, 7, 11);
        addEdge(2, 3, 7);
        addEdge(2, 8, 2);
        addEdge(2, 5, 4);
        addEdge(3, 4, 9);
        addEdge(3, 5, 14);
        addEdge(4, 5, 10);
        addEdge(5, 6, 2);
        addEdge(6, 7, 1);
        addEdge(6, 8, 6);
        addEdge(7, 8, 7);
        cout << Prim(0,9);
}
