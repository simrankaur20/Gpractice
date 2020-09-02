#include<bits/stdc++.h>
using namespace std;
class Edge{
public:
    int src, dest,wt;
    Edge(int x, int y, int z)
    {
        src = x;
        dest = y;
        wt = z;
    }

};

class mycomp{
public :
    int operator()(const Edge &e1, const Edge &e2)
    {
        return e1.wt > e2.wt;
    }
};

int prims(vector<Edge> &graph, int src)
{

    vector<bool> visited(8, false);
    priority_queue<Edge, vector<Edge>, mycomp> pq;
    vector<Edge> finalgraph;

    for(Edge e : graph)
    {
        pq.push(e);
    }
    int counter = 0;
    int ans = 0;
    while(true)
    {
        Edge curr = pq.top();
        pq.pop();
        if(!visited[curr.src])
        {
            visited[curr.src] = true;
            finalgraph.push_back(curr);
            counter++;
            ans += curr.wt;
            if(counter == 7)
            {
                break;
            }
        }
    }

    for(Edge e : finalgraph)
    {
        cout<<e.src << " "<<e.dest<<" " <<e.wt<<endl;
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



        cout<<prims(g , 0);


}
