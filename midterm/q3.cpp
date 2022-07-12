#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cmp(const pair<int ,int>a, const pair<int,int> b){
    return a.second<b.second;
}

int main(){
    int casenum,actnum;
    int numWork=0;
    vector<pair<int,int>> arr;
    cin>>casenum;
    for(int i=0;i<casenum;i++){
        cin>>actnum;
        for(int j=0;j<actnum;j++){
            pair<int ,int> tmp;
            cin>>tmp.first>>tmp.second;
            arr.push_back(tmp);
        }
    
        sort(arr.begin(),arr.end(),cmp);

        int et_Fh_Idx=0;
        int fh_time=arr[et_Fh_Idx].second;
        int next=et_Fh_Idx;
        bool stop=false;
        numWork++;
        while(!stop){
            while(true){
                next=next+1;
                if(next>actnum-1) break;
                if(arr[next].first>=fh_time){
                    break;
                }
            }
            if(next>actnum-1) {
                stop=true;
                break;
            }
            et_Fh_Idx=next;
            fh_time=arr[et_Fh_Idx].second;
            numWork++;
        }

        cout<<numWork<<endl;
        numWork=0;
        arr.clear();
    }
    return 0;
}