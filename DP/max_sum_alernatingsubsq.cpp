#include<bits/stdc++.h>
using namespace std;
int maxsumalternating(vector<int> &arr)
{
    vector<int> incr(arr.size() , INT_MIN) , decr(arr.size(), INT_MIN);

    for(int i = arr.size() - 1 ; i >= 0 ; i--)
    {
        if(i == arr.size() - 1)
        {
            incr[i] = arr[i];
            decr[i] = arr[i];
            continue;
        }

        for(int j = i + 1 ; j  <arr.size() ; j++)
        {
            //fill incr
            if(arr[j] < arr[i])
            {
                incr[i] = max(incr[i] , arr[i] + decr[j]);
            }
            if(arr[j] > arr[i])
            {
                decr[i] = max(decr[i] , arr[i] + incr[j]);
            }
        }

    }
    return incr[0];
}
int main()
{
    vector<int> arr{4, 8, 2, 5, 6, 8} ;

    cout << maxsumalternating(arr);

}
