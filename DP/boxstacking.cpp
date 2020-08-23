#include<bits/stdc++.h>
using namespace std;

class Box{
    public :
        int length, breadth, height;
        Box(int length, int breadth,int  height){
            this->length = length;
            this->breadth = breadth;
            this->height = height;
        }
        Box(){
        }

};
bool comparebases(Box b1, Box b2){
    return (b1.length * b1.breadth) > (b2.length * b2.breadth);
}
int maxheight(vector<Box> &boxes){
    vector<Box> allpossiblerotaions(3*boxes.size());

    int index = 0;

    for(int i = 0 ; i < boxes.size() ; i++){
        allpossiblerotaions[index].height = boxes[i].length;
        allpossiblerotaions[index].length = max(boxes[i].breadth, boxes[i].height);
        allpossiblerotaions[index++].breadth= min(boxes[i].breadth, boxes[i].height);

        allpossiblerotaions[index].height = boxes[i].breadth;
        allpossiblerotaions[index].length = max(boxes[i].height, boxes[i].length);
        allpossiblerotaions[index++].breadth= min(boxes[i].height, boxes[i].length);

        allpossiblerotaions[index].height = boxes[i].height;
        allpossiblerotaions[index].length = max(boxes[i].length, boxes[i].breadth);
        allpossiblerotaions[index++].breadth= min(boxes[i].length, boxes[i].breadth);
    }

    sort(allpossiblerotaions.begin(), allpossiblerotaions.end(), comparebases);
    vector<int> lis(allpossiblerotaions.size(), 0);
    int maxlen = 0;
    for(int i=0;i<allpossiblerotaions.size() ;i++){
        lis[i] = allpossiblerotaions[i].height;
        for(int j = 0 ; j  < i ; j++){
            if(allpossiblerotaions[j].length > allpossiblerotaions[i].length && allpossiblerotaions[j].breadth > allpossiblerotaions[i].breadth){
                lis[i] = max(lis[i] , lis[j] + allpossiblerotaions[i].height);
            }
        }
        maxlen = max(maxlen, lis[i]);
    }
    return maxlen;
}
int main()
{

    vector<Box> boxes{ {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };


    cout<<maxheight(boxes);
}
