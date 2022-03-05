#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i, a, b) for(int i = a; i < b; i++)
#define g(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/g(a,b)
#define lb(v,key) lower_bound(v.begin(), v.end(), key)
#define ub(v,key) upper_bound(v.begin(), v.end(), key)
#define srt(v) sort(v.begin(), v.end())
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

int n, m;
int solve(int arr[1000][1000], int n, int m){
    int dp[n][m];
    mem(dp, 0);
    int len = 0;
    fr(i, 0, n){
        fr(j, 0, m){
            if(i || j){
                if(i>0 && abs(arr[i][j]-arr[i-1][j])==1){
                    dp[i][j] = max(dp[i][j], dp[i-1][j] + 1);
                    len = max(dp[i][j], len);
                }
                if(j>0 && abs(arr[i][j]-arr[1][j-1])==1){
                    dp[i][j] = max(dp[i][j], dp[i][j-1] + 1);
                    len = max(dp[i][j], len);
                }
            }
        }
    }
    return len;
}

void nd(){
    int n, m;
    cin>>n>>m;
    int arr[n][m];
    fr(i, 0, n){
        fr(j, 0, m){
            cin>>arr[i][j];
        }
    }
    int ans = -1;
    cout<<solve(arr, n, m)<<endl;
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