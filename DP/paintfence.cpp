#include<bits/stdc++.h>
using namespace std;
int paintfence(int n, int k)
{
    vector<int> samecolor(n + 1,0), diffcolor(n + 1,0);
    for(int i = 0 ;i  < n + 1; i++)
    {
        if(i == 0)
        {
            samecolor[i] = 0;
            diffcolor[i] = k;
            continue;
        }
        samecolor[i] = diffcolor[i-1];
        diffcolor[i] = (samecolor[i-1] + diffcolor[i-1])*(k-1);
    }

    return max(samecolor[n] , diffcolor[n]);
}
 int main()
 {
    int n,k;
    cin>>n>>k;
    cout<<paintfence(n,k);
 }
