#include<bits/stdc++.h>
using namespace std;
#define ll long long
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

void solve(int arr[], int n, int m){
    int dp[n+1][m+1];
    fr(i, 0, n+1){
        fr(j, 0, m+1){
            if(j == 0)  dp[i][j] = 0;
            if(i == 0)  dp[i][j] = 1;
        }
    }
    fr(i, 1, n+1){
        fr(j, 1, m+1){
            if(arr[j-1] <= i) dp[i][j] = dp[i][j-1] + dp[i-arr[j-1]][j];
            else    dp[i][j] = dp[i][j-1];
        }
    }
    cout<<dp[n][m];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    int arr[m];
    fr(i, 0, m) cin>>arr[i];
    solve(arr, n, m);

    return 0;
}