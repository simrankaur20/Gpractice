#include<bits/stdc++.h>
using namespace std;
class Edge{
public:
    int u,v,wt;
    Edge(int u, int v, int wt)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

bool mycomp(Edge e1, Edge e2)
{
    return e1.wt < e2.wt;
}

class DSU{
public:
    vector<int> parents,ranks;
    DSU(int n)
    {
        for(int i = 0 ; i  < n ; i++)
        {
            parents.push_back(i);
            ranks.push_back(1);
        }
    }

    int findv(int x)
    {
        if(parents[x] == x)
            return x;
        int temp = findv(parents[x]);
        parents[x] = temp;
        return temp;
    }

    void union_vertices(int x, int y)
    {
        cout<<"union "<<x<< " " << y<<endl;
        int p1 = findv(x);
        int p2 = findv(y);
        if(p1 != p2)
        {
            if(ranks[p1] < ranks[p2])
            {
                parents[p1] = p2;
            }
            else if(ranks[p1] > ranks[p2])
            {
                parents[p2] = p1;
            }
            else
            {
                parents[p1] = p2;
                ranks[p2]++;
            }
        }
    }
};

int kruskal(vector<Edge> &g , int V)
{
    DSU dsu(V);
    int ans = 0;
    for(Edge e : g)
    {
        int p1 = dsu.findv(e.u);
        int p2 = dsu.findv(e.v);
        if(p1 == p2) continue;
        cout<<e.wt<<endl;
        ans += e.wt;
        dsu.union_vertices(e.u, e.v);
    }
    return ans;

}
int main()
{
    vector<Edge> g;
    g.push_back(Edge(0, 1, 4));
    g.push_back(Edge(0, 7, 8));
    g.push_back(Edge(1, 2, 8));
    g.push_back(Edge(1, 7, 11));
    g.push_back(Edge(2, 3, 7));
    g.push_back(Edge(2, 8, 2));
    g.push_back(Edge(2, 5, 4));
    g.push_back(Edge(3, 4, 9));
    g.push_back(Edge(3, 5, 14));
    g.push_back(Edge(4, 5, 10));
    g.push_back(Edge(5, 6, 2));
    g.push_back(Edge(6, 7, 1));
    g.push_back(Edge(6, 8, 6));
    g.push_back(Edge(7, 8, 7));

    sort(g.begin(), g.end() , mycomp);

    cout << kruskal(g , 9);
}
