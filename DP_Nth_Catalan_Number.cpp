#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(i, a, b) for(int i = a; i < b; i++)
#define g(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/g(a,b)
#define lb(v,key) lower_bound(v.begin(), v.end(), key)
#define ub(v,key) upper_bound(v.begin(), v.end(), key)
#define srt(v) sort(v.begin(), v.end())


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


int max3(int a, int b, int c){
    if(a > b)
        return (a > c) ? a : c;
    else
        return (b > c) ? b : c;
}


int min3(int a, int b, int c){
    if(a < b)
        return (a < c) ? a : c;
    else
        return (b < c) ? b : c;
}

void solve(int n){
    unsigned ll dp[n+2];
    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    fr(i, 3, n+2)   fr(j, 0, i)   dp[i] += (dp[j]*dp[i-j-1]);
    cout<<dp[n]<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    solve(n);

    return 0;
}