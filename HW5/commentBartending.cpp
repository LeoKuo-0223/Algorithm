#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int N,M,K;
    int con,ans,target;
    vector<pair<int,int>> array;
    multiset<pair<int,int>> subset;
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        cin>>con;
        pair<int ,int> tmp;
        tmp.first=con; tmp.second=i;
        array.push_back(tmp);
    }
    subset.insert(array.begin(),array.begin()+M);
    multiset<pair<int,int>>::iterator iter;
    iter=subset.begin();
    for(int i=0;i<K-1;i++){
        iter++;
    }
    cout<<iter->first<<" ";
    target=iter->first;
    for(int j=1;j<N-M+1;j++){
        subset.erase(array[j-1]);
        subset.insert(array[M-1+j]);
        if(array[j-1].first!=target){
            if(array[j-1].first<target && array[M-1+j].first> target) ++iter;
            if(array[j-1].first>target && array[M-1+j].first< target) --iter;
        }else{
            iter=subset.begin();
            for(int i=0;i<K-1;i++){
                iter++;
            }
        }
        cout<<iter->first<<" ";
        target=iter->first;
    }
    return 0;
}