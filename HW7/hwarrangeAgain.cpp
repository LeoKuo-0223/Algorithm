#include<iostream>
#include <cstring>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;

int cmp(const tuple<int,int,int> a, const tuple<int,int,int> b){
    return get<1>(a) < get<1>(b);
}
int main(){
    int n;
    cin>>n;
    vector<tuple<int,int,int>> arr;
    int s,duetime,t,ans=-1;
    for(int i=0;i<n;i++){
        cin>>s>>duetime>>t;
        arr.push_back(make_tuple(s,duetime,t));  
    }
    sort(arr.begin(),arr.end(),cmp);
    int maxT=get<1>(*(arr.end()-1));
    int dp[maxT+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=get<1>(arr[i]) ; j>=get<2>(arr[i]) ; j--){
            dp[j]=max(dp[j], dp[j-get<2>(arr[i])]+get<0>(arr[i]));
            ans=max(ans, dp[j]);
        }
    }
    cout<<ans;
    return 0;
}
