#include<iostream>
#include <cstring>
using namespace std;

int main(){
    int n,remainT;
    cin>>n>>remainT;
    int s[n];
    int time[n];
    int dp[remainT+1];
    for(int i=0;i<n;i++){
        cin>>s[i]>>time[i];
    }
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=remainT;j>=time[i];j--){
            dp[j]=max(dp[j], dp[j-time[i]]+s[i]);
        }
    }
    cout<<dp[remainT];
    return 0;
}



// #include <iostream>
// #include <cstring>
// using namespace std;
 
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
 
//     int N, m; //N（<30000）表示总钱数，m（<25）为希望购买物品的个数
//     cin >> N >> m;
//     int v[m], w[m]; //v表示该物品的价格(v<=10000)，p表示该物品的重要度(1~5)
//     int dp[m+1][N+1];
 
//     for (int i=0; i<m; i++){
//         cin >> v[i] >> w[i];
//     }
//     memset(dp, 0, sizeof(dp));
//     for (int i=0; i<m; i++){
//         for (int j=0; j<=N; j++){
//             if (j < v[i]) {
//                 dp[i+1][j] = dp[i][j];
//             } else {
//                 dp[i+1][j] = max(dp[i][j], dp[i][j - v[i]] + v[i] * w[i]);
//             }
//         }
//     }
//     cout << dp[m][N] << '\n';
//     return 0;
// }