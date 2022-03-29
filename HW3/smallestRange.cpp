#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
    int val, ListIdx;
    bool isRecord=false;
}typedef Node;

bool cmp(Node const &a,Node const &b){
    return a.val<b.val;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numList,minrange=200001,allrecorded=0,min=100001,minLoc=0;
    Node *currentNode;
    vector<Node> array;
    cin>>numList;
    vector<Node> ListIdxArray(numList);
    for(int i=0;i<numList;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            int elements;
            cin>>elements;
            Node node; 
            node.val=elements;node.ListIdx=i;
            array.push_back(node);
        }
    }
    sort(array.begin(),array.end(),cmp);
    for(auto it=array.begin();it!=array.end();++it){
        ListIdxArray[it->ListIdx].val=it->val;
        if(!ListIdxArray[it->ListIdx].isRecord){
            ListIdxArray[it->ListIdx].isRecord=true;
            allrecorded++;
        }
        if(allrecorded==numList){
            min=(*min_element(ListIdxArray.begin(),ListIdxArray.end(),cmp)).val;
            int tmprange=(it->val)-min;
            if(tmprange<minrange) {
                minrange=tmprange;
                minLoc=min;
            }
        }
        if(it==array.end()-1) cout<<minLoc<<" "<<minLoc+minrange;
    }
    return 0;
}