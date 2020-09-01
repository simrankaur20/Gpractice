class Solution {
public:
    class DSU{
      public:
        unordered_map<char,char> parents;
        unordered_map<char, int> ranks;

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
        void insert(int x)
        {
            if(!parents.count(x))
            {
                parents[x] = x;
                ranks[x] = 1;
            }
        }
        void union_vertices(int x, int y)
        {
            int parx = find(x);
            int pary = find(y);
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
    };

    bool equationsPossible(vector<string>& equations) {

        DSU dsu;
        for(int i = 0 ; i < equations.size() ; i++)
        {
            string curr = equations[i];
            dsu.insert(curr[0]);
            dsu.insert(curr[3]);
            if(curr[1] == '=' && curr[2] == '=')
            {
                dsu.union_vertices(curr[0], curr[3]);
            }
        }

        for(int i = 0; i < equations.size() ; i++)
        {
            string curr = equations[i];
            if(curr[1] == '!' && curr[2] == '=')
            {
                dsu.insert(curr[0]);
             dsu.insert(curr[3]);
                int x = dsu.find(curr[0]);
                int y = dsu.find(curr[3]);
                if(x == y)
                {
                    return false;
                }
            }
        }
        return true;


    }
};
