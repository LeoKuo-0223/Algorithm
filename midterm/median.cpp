#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int solution(vector<int> arr,int n,int mid){

    if(n==1) return *arr.begin();
    vector<int>small;
    vector<int>Big;
    vector<int> median;
    int pivot, tmp[5];

    for(int i=0;i<n/5;i++){
        for(int j=0;j<5;j++){
            tmp[j]=(arr[i*5+j]);
        }
        sort(tmp,tmp+5);
        median.push_back(tmp[2]);
    }
    int mode=n%5;
    if(mode){ //n%5!=0
        for(int i=0;i<mode;i++){
            tmp[i] = arr[n-mode+i];
        }
        sort(tmp,tmp+mode);
        median.push_back(tmp[(int)((mode-1)/2)]);
    }

    int medianNum=(n+4)/5;
    int tmpmid=(int)((medianNum+1)/2);

    pivot=solution(median,medianNum, tmpmid);
    cout<<"pivot: "<<pivot<<endl;
    int cnt=1;



    //分兩堆
    for(int i=0;i<n;i++){
        if(pivot>arr[i]){
            small.push_back(arr[i]);
            cnt++;
        }else if(pivot<arr[i]){
            Big.push_back(arr[i]);
        }
    }

    if(cnt==mid) return pivot;
    else if(mid<cnt) return solution(small, small.size(), mid);
    else if(mid>cnt) return solution(Big, Big.size(), mid-cnt);

}
int main(){
    int n,tmp,mid;
    cin>>n;
    vector<int> arr;

    for(int i=0;i<n;i++){
        cin>>tmp;
        arr.push_back(tmp);
    }

    mid=solution(arr,n,(n+1)/2);
    cout<<"answer: "<<mid<<endl;
    return 0;
}