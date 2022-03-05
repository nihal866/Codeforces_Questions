#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fri(i, a, b) for(ll i = a; i < b; i++)
#define frd(i, a, b) for(ll i = a; i >= b; i--)
#define g(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/g(a,b)
#define lb(v,key) lower_bound(v.begin(), v.end(), key)
#define ub(v,key) upper_bound(v.begin(), v.end(), key)
#define srtvec(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())
#define srt(arr,n) sort(arr, arr+n)
#define mem(arr,key) memset(arr, key, sizeof(arr))


const int N = 1000000;
bool isPrime[N];
set<int> s;


void preCalculatorPrime(){
    fill(isPrime+2, isPrime+N, true);
    for(int i = 2; i*i < N; i++){
        for(int j = i*i; j < N; j=j+i)
            isPrime[j] = false;
    }
    for(int i = 2; i < N; i++){
        if(isPrime[i])
            s.insert(i);
    }
}


const long long M = 1e9 + 7;
long long mod(long long x){
    return ((x%M + M)%M);
}


long long add(long long a, long long b){
    return mod(mod(a) + mod(b));
}


long long mul(long long a, long long b){
    return mod(mod(a) * mod(b));
}


long long max3(long long a, long long b, long long c){
    if(a > b)
        return (a > c) ? a : c;
    else
        return (b > c) ? b : c;
}


long long min3(long long a, long long b, long long c){
    if(a < b)
        return (a < c) ? a : c;
    else
        return (b < c) ? b : c;
}


void nd(){
    int n;
    cin>>n;
    int dp[n+1] = {0}, rest[n+1] = {0}, arr[n];
    fri(i, 0, n){
        cin>>arr[i];
        if(!arr[i]){
            rest[i+1] = 1;
            dp[i+1] = 0;
            continue;
        }
        if(arr[i] == 1){
            if(dp[i]==1){
                dp[i+1] = 0;
                rest[i+1] = 1;
            }
            else    dp[i+1] = 1;
            continue;
        }
        if(arr[i] == 2){
            if(dp[i]==2){
                dp[i+1] = 0;
                rest[i+1] = 1;
            }
            else    dp[i+1] = 2;
            continue;
        }
        if(arr[i] == 3){
            if(dp[i] == 0){
                dp[i+1] = 0;
            }
            else    dp[i+1] = (dp[i] == 1) ? 2 : 1;
            continue;
        }
    }
    int sum = 0;
    fri(i, 1, n+1)  sum += rest[i];
    cout<<sum<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--){
        nd();
    }
    return 0;
}