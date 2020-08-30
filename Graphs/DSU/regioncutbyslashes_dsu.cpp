class Solution {
public:
    class DSU{
      public :
        vector<int> parents, ranks;
        DSU(int n)
        {
            for(int i = 0 ; i < n ; i++)
            {
                parents.push_back(i);
                ranks.push_back(1);
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
        void unionvertices(int x, int y)
        {
            int p1 = find(x) , p2 = find(y);
            if(p1!= p2)
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
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size() + 1;
        DSU dsu(n*n);
        int ans = 1;
        for(int i = 0 ; i < n ; i++)
        {
            int cellno = i * n + 0;
            dsu.unionvertices(0,cellno);
            int c2 = 0 * n + i;
            dsu.unionvertices(0,c2);
        }
        for(int i = n-1;i >=0 ; i--)
        {
            int cellno = i * n + (n-1);
            dsu.unionvertices(0,cellno);
            int c2 = (n-1) * n + i;
            dsu.unionvertices(0,c2);
        }
        for(int i = 0 ; i < n - 1 ; i++)
        {
            for(int j = 0 ; j  < n-1 ; j++)
            {
                if(grid[i][j] == '/')
                {
                    int x1 = i+1;
                    int x2 = i ;
                    int y1 = j;
                    int y2 = j+1;
                    int c1 = x1 * (n) + y1;
                    int c2 = x2*(n) + y2;
                    if(dsu.find(c1) == dsu.find(c2))
                    {
                        ans++;
                    }
                    else
                    {
                        dsu.unionvertices(c1,c2);
                    }
                }
                else if(grid[i][j] == '\\')
                {
                    int x1 = i;
                    int y1 = j;
                    int x2 = i + 1;
                    int y2 = j + 1;
                    int c1 = x1 * (n) + y1;
                    int c2 = x2*(n) + y2;
                    if(dsu.find(c1) == dsu.find(c2))
                    {
                        ans++;
                    }
                    else
                    {
                        dsu.unionvertices(c1,c2);
                    }

                }
            }
        }
        return ans;
    }
};
