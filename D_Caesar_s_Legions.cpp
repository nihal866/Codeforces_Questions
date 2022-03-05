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

const long long M = 1e8;
long long mod(long long x){	return ((x%M + M)%M); }
long long add(long long a, long long b){	return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b){	return mod(mod(a) * mod(b)); }

int h, k;
int dp[101][101][11][11];
int getAns(int n, int m, int k1, int k2){
    if((n+m) == 0)  return 1;
    if(dp[n][m][k1][k2] != -1)  return dp[n][m][k1][k2];
    int x = 0;
    if(n>0 && k1>0) x = getAns(n-1, m, k1-1, k);
    int y = 0;
    if(m>0 && k2>0) y = getAns(n, m-1, h, k2-1);
    return dp[n][m][k1][k2] = add(x,y);
}

void nd(){
    int n, m;
    cin>>n>>m>>h>>k;
    mem(dp, -1);
    cout<<getAns(n, m, h, k);
}
    
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--){
        nd();
    }
    return 0;
}