#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>array;
    int n,tmp,Maxsum=0,sum=0;
    int tmpheadidx,tailidx,headidx;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        array.push_back(tmp);
    }
    tmpheadidx=headidx=tailidx=0;
    for(int i=0;i<n;i++){
        sum =sum+array[i];

        if(sum<0){
            sum=0;
            tmpheadidx=i+1;
        }
        if(sum>Maxsum){
            Maxsum=sum;
            headidx=tmpheadidx;
            tailidx=i;
        }
    }

    cout<<Maxsum<<" "<<headidx+1<<" "<<tailidx+1;
    return 0;
}
