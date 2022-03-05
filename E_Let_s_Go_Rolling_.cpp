#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define fri(i, a, b) for(int i = a; i < b; i++)
#define frd(i, a, b) for(int i = a; i >= b; i--)
#define g(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/g(a,b)
#define vll vector<int>
#define lb(v,key) lower_bound(v.begin(), v.end(), key)
#define ub(v,key) upper_bound(v.begin(), v.end(), key)
#define srtvec(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define srt(arr,n) sort(arr, arr+n)
#define mem(arr,key) memset(arr, key, sizeof(arr))

int n;
pair<int, int> arr[3001];
int dp[3001][3001];
int getAns(int pos, int prev){
    if(pos == n)    return 0;
    if(dp[pos][prev] != -1e15)   return dp[pos][prev];
    int x = arr[pos].second + getAns(pos+1, pos);
    int y = abs(arr[pos].first - arr[prev].first) + getAns(pos+1, prev);
    return dp[pos][prev] = min(x, y);
}

// void nd(){
//     int n;
//     cin>>n;
//     vector<vector<int>> arr(n, vector<int>(2));
//     fri(i, 0, n)    cin>>arr[i][0]>>arr[i][1];
//     srtvec(arr);
//     vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(2));
//     dp[0][1] = dp[0][0] = {arr[0][1], arr[0][0]};
//     fri(i, 1, n){
//         auto a = min(dp[i-1][0], dp[i-1][1]);
//         dp[i][0].first = a.first + arr[i][1];
//         dp[i][0].second = arr[i][0];

//         if((dp[i-1][0].first + (arr[i][0]-dp[i-1][0].second)) <= (dp[i-1][1].first + (arr[i][0]-dp[i-1][1].second))){
//             dp[i][1].first = (dp[i-1][0].first + (arr[i][0]-dp[i-1][0].second));
//             dp[i][1].second = dp[i-1][0].second;
//         }
//         else{
//             dp[i][1].first = (dp[i-1][1].first + (arr[i][0]-dp[i-1][1].second));
//             dp[i][1].second = dp[i-1][1].second;
//         }
//     }
//     cout<<min(dp[n-1][0].first, dp[n-1][1].first)<<endl;
// }

void nd(){
    cin>>n;
    fri(i, 0, n)    cin>>arr[i].first>>arr[i].second;
    fri(i, 0, n+1){
        fri(j, 0, n+1)    dp[i][j] = -1e15;
    }
    int ans = arr[0].second + getAns(1, 0);
    cout<<ans<<endl;
}
    
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
 //   cin>>t;
    while(t--){
        nd();
    }
    return 0;
}