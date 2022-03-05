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

const long long M = 1e9 + 7;
long long mod(long long x){	return ((x%M + M)%M); }
long long add(long long a, long long b){	return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b){	return mod(mod(a) * mod(b)); }
long long max3(long long a, long long b, long long c){
    if(a > b)	return (a > c) ? a : c;
    else	return (b > c) ? b : c; }
long long min3(long long a, long long b, long long c){
    if(a < b)	return (a < c) ? a : c;
    else	return (b < c) ? b : c; }
    
int k;
int dp[100005], pref[100005];

void calc(){
    mem(pref, 0);
    mem(dp, 0);
    fri(i, 1, 1e5 + 5){
        if(i < k)   dp[i] = 1;
        else if(i == k) dp[i] = 2;
        else    dp[i] = add(dp[i-1], dp[i-k]);
        pref[i] = add(dp[i], pref[i-1]);
    }
}

void nd(){
    int a, b;
    cin>>a>>b;
    cout<<add(pref[b], -1*pref[a-1])<<endl;
}
    
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t>>k;
    calc();
    while(t--){
        nd();
    }
    return 0;
}