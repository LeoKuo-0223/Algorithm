#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

struct Wine{
    int pos;
    int con;
}typedef Wine;


bool cmp(const Wine &a,const Wine &b){
    int a_con=a.con;int b_con=b.con;
    return a_con<b_con;
}

bool Poscmp(const Wine &a,const Wine &b){
    int a_pos=a.pos;int b_pos=b.pos;
    return a_pos<b_pos;
}

int binarySearch(vector<Wine> &arr, int l, int r, int target){
    if (r >= l) {
        int mid = (l+r)/2;
        if (arr[mid].con == target){
            if(arr[mid-1].con == target && mid!=0) return binarySearch(arr, l, mid - 1, target);
            return mid;
        }
        if (arr[mid].con > target)
            return binarySearch(arr, l, mid - 1, target);
        else return binarySearch(arr, mid + 1, r, target);
    }else{
        return l;
    }
    
}


pair<int,bool> binarySearch_pos(vector<Wine> &arr, int l, int r, int target){
    if (r >= l) {
        int mid = (l+r)/2;
        if (arr[mid].pos == target){
            if(arr[mid-1].pos == target && mid!=0) return binarySearch_pos(arr, l, mid - 1, target);
            pair<int,bool> result;
            result.first=mid;
            result.second=true;
            return result;
        }
        
        if (arr[mid].pos > target)
            return binarySearch_pos(arr, l, mid - 1, target);
        else return binarySearch_pos(arr, mid + 1, r, target);
    }else{
        pair<int,bool> result;
        result.first=l;
        result.second=false;
        return result;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,Q;
    int WinePos,concentration;
    int JudgePos,idealconcentration;
    vector<Wine> sortWineConctn;
    vector<Wine> sortWinePos;
    vector<int> judge_ans;
    cin>>N>>Q;
    for(int i=0;i<N;i++){
        cin>>WinePos>>concentration;
        Wine tmp; tmp.con=concentration; tmp.pos=WinePos;
        sortWineConctn.push_back(tmp);
    }
    sort(sortWineConctn.begin(),sortWineConctn.end(),cmp);
    for(int j=0;j<Q;j++){
        cin>>JudgePos>>idealconcentration;
        int targetpos=binarySearch(sortWineConctn,0,N-1,idealconcentration);
        if(targetpos<=N-1){ //answer in the range
            sortWinePos.insert(sortWinePos.begin(),sortWineConctn.begin()+targetpos,sortWineConctn.end());
            sort(sortWinePos.begin(),sortWinePos.end(),Poscmp);
            pair<int,bool> ans=binarySearch_pos(sortWinePos,0,sortWinePos.size()-1,JudgePos);
            if(ans.second==true){
                judge_ans.push_back(sortWinePos[ans.first].pos);
            }else{
                if(ans.first>=sortWinePos.size()){
                    judge_ans.push_back(sortWinePos[ans.first-1].pos);
                }else if(ans.first <=0){
                    judge_ans.push_back(sortWinePos[ans.first].pos);
                }else{
                    if(abs(JudgePos-sortWinePos[ans.first].pos)>abs(JudgePos-(sortWinePos[ans.first-1].pos))){
                        judge_ans.push_back(sortWinePos[ans.first-1].pos);
                    }else if(abs(JudgePos-sortWinePos[ans.first].pos)==abs(JudgePos-(sortWinePos[ans.first-1].pos))){
                        judge_ans.push_back(sortWinePos[ans.first-1].pos);
                    }else{
                        judge_ans.push_back(sortWinePos[ans.first].pos);
                    }
                }
            }
        }else{  //there is no answer in the range
            judge_ans.push_back(-1);
        }
        sortWinePos.clear();
        cout<<judge_ans[j]<<endl;
    }
    return 0;
}