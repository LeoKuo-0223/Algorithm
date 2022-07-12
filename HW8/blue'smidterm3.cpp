#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int TwoWay_LIS(vector<int> arr, int n){
    int dp1[n];
    dp1[0]=1;
    for (int i=1; i<n; i++){
        dp1[i]=1; //initial
        for (int j=0; j<i; j++)
            if (arr[i] > arr[j]) 
                dp1[i] = max(dp1[i], dp1[j]+1);
    }

    int dp2[n];
    dp2[n-1]=1;
    for (int i=n-2; i>=0; i--){
        dp2[i]=1; //initial
        for (int j=n-1; j>i; j--)
            if (arr[i] > arr[j])
                dp2[i] = max(dp2[i], dp2[j]+1);
        
    }
    int max=0;
    for(int i=0;i<n;i++){
        if((dp1[i])+dp2[i]>max){
            max=dp1[i]+dp2[i];
        }
    }
    return n-max+1;
}

 
int main(){
    int n;
    cin>>n;
    vector<int> array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int ans=TwoWay_LIS(array,n);
    cout<<ans;
    

    return 0;
}




