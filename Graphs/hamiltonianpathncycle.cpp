#include<bits/stdc++.h>
using namespace std;
class edge{
public :
    int v;
    int wt;
    edge(int x, int y)
    {
        v = x;
        wt = y;
    }
};
vector<vector<edge>> graph(5, vector<edge>());
void addEdge(int s, int d, int w)
{
    graph[s].push_back(edge(d,w));
    graph[d].push_back(edge(s,w));
}
void hamiltonian(int src, int osrc, string psf, unordered_set<int> &vis)
{
    if(vis.size() == graph.size() - 1)
    {
        cout<<"base";
        bool iscycle = false;
        for(edge e : graph[src])
        {
            if(e.v == osrc)
            {
                psf += "*";
                iscycle = true;
                break;
            }
        }
        if(!iscycle)
            psf += ".";

        cout << psf<<endl;
        return ;

    }
    vis.insert(src);
    cout<<src<<endl;
    for(edge e : graph[src])
    {
        if(!vis.count(e.v))
        {
            hamiltonian(e.v,osrc,psf + to_string(e.v), vis);
        }
    }
    vis.erase(src);
}
int main()
{

        addEdge(0, 1, 4);
        addEdge(1, 2, 8);
        addEdge(2, 3, 8);
        addEdge(3, 4, 11);

        unordered_set<int> vis;
        hamiltonian(0,0, "0", vis);

}
