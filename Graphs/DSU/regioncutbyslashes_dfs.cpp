class Solution {
public:

    void dfs(vector<vector<int>> &graph, int x, int y)
    {
        if(x < 0 || y < 0 || x >= graph.size() || y >= graph[0].size() || graph[x][y])
        {
            return;
        }
        graph[x][y] = 1;
        vector<vector<int>> dir{{-1,0} , {1,0} , {0,1} , {0,-1}};
        for(int i = 0 ; i  < 4 ; i++)
        {
            dfs(graph , x + dir[i][0] , y + dir[i][1] );
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> mat(3*n, vector<int>(3*n, 0));
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == '/')
                {
                    mat[3*i][3*j + 2] = 1;
                    mat[3*i + 1][3*j + 1] = 1;
                    mat[3*i + 2][3*j] = 1;

                }
                else if(grid[i][j] == '\\')
                {
                    mat[3*i][3*j ] = 1;
                    mat[3*i + 1][3*j + 1] = 1;
                    mat[3*i + 2][3*j + 2] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i  < 3*n ; i++)
        {
            for(int j = 0 ; j < 3*n ; j++)
            {
                if(mat[i][j] == 0)
                {

                    dfs(mat, i, j);
                    ans++;

                }
            }
        }
        return ans;

    }
};
