#include<bits/stdc++.h>
using namespace std;
int buildbridges(vector<pair<int,int>> &cities){
    sort(cities.begin(), cities.end());

    int maxlength = 1;
    vector<int> lis(cities.size() , 1);

    for(int i =0 ; i< cities.size() ; i++){
        for(int j = 0 ; j < i; j++){
            if(cities[j].second < cities[i].second){
                lis[i] = max(lis[i] , lis[j] + 1);
            }
            maxlength = max(maxlength , lis[i]);
        }
    }
    return maxlength;
}
int main(){
    vector<pair<int, int>> cities{{6, 2}, {4, 3}, {2, 6}, {1, 5}};
    cout<<buildbridges(cities);
    return 0;
}
