#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

struct Wine{
    int pos;
    int con;
}typedef Wine;


bool Poscmp(const Wine &a,const Wine &b){
    int a_pos=a.pos;int b_pos=b.pos;
    return a_pos<b_pos;
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
    vector<Wine> sortWinePos;
    cin>>N>>Q;
    for(int i=0;i<N;i++){
        cin>>WinePos>>concentration;
        Wine tmp; tmp.con=concentration; tmp.pos=WinePos;
        sortWinePos.push_back(tmp);
    }
    sort(sortWinePos.begin(),sortWinePos.end(),Poscmp);
    for(int j=0;j<Q;j++){
        cin>>JudgePos>>idealconcentration;
        pair<int,bool> ans=binarySearch_pos(sortWinePos,0,sortWinePos.size()-1,JudgePos);
        int front=ans.first,back=ans.first;
        int idx=ans.first;
        bool fstop=false;
        bool bstop=false;
        
        if(front-1>=0){
            front--;
        }else fstop=true;

        while(!(fstop && bstop)){
            while(sortWinePos[front].con<idealconcentration && !fstop){
                if(front-1>=0) front--;
                else {
                    fstop=true;
                    break;
                }
            }
            while(sortWinePos[back].con<idealconcentration && !bstop){
                if(back+1<N) back++;
                else {
                    bstop=true;
                    break;
                }
            }
            if(!fstop && !bstop){
                if(abs(JudgePos-sortWinePos[front].pos)<=abs(JudgePos-sortWinePos[back].pos)){
                    cout<<sortWinePos[front].pos<<endl;
                    break;
                }else{
                    cout<<sortWinePos[back].pos<<endl;
                    break;
                }
            }else if(fstop && !bstop){
                cout<<sortWinePos[back].pos<<endl;
                break;
            }else if(!fstop && bstop){
                cout<<sortWinePos[front].pos<<endl;
                break;
            }
        }
        if(fstop && bstop) cout<<-1<<endl;

        


    }
    return 0;
}