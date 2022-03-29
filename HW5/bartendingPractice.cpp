#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
map<string,int> record;

bool cmp(const pair<string, int> &a,const  pair<string ,int> &b){
    if(a.second>b.second) return true;
    else if(a.second==b.second){
        int maxlength=max(a.first.size(),b.first.size());
        for(int i=0;i<maxlength;i++){
            if(a.first[i] == b.first[i]) continue;
            else{
                return a.first[i]<b.first[i];
            }
        }
    }else return false;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // srand (time(NULL));
    int N,K;
    string name;
    cin>>N>>K;
    vector<pair<string,int>> array;
    for(int i=0;i<N;i++){
        cin>>name;
        auto it = record.find(name);
        if(it!=record.end()) record[name]++;
        else record[name]=0;
    }
    array.insert(array.begin(),record.begin(),record.end());

    sort(array.begin(),array.end(),cmp);
    cout<<array[K-1].first;
    return 0;
}