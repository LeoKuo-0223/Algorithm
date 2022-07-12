#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n, sum=0, halfsum;
    cin>>n;
    int weightArr[n+1];
    int dp[50001];
    for(int i=1; i<=n; i++){
        cin>>weightArr[i];
        sum+=weightArr[i];
    }
    memset(dp,0,sizeof(dp));
    halfsum=sum/2;
    for(int i=1; i<=n; i++){
        for(int j=halfsum; j>=weightArr[i]; j--){
            dp[j] = max(dp[j], dp[j-weightArr[i]]+weightArr[i]);
        }
    }

    cout<<sum - dp[halfsum]*2;

    return 0;
}
