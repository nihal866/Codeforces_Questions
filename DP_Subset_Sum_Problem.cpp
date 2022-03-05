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

void solve(int n, int arr[], int sum){
    bool dp[n+1][sum+1];
    fr(i, 0, sum+1) dp[0][i] = false;
    fr(i, 0, n+1)   dp[i][0] = true;

    fr(i, 1, n+1){
        fr(j, 1, sum+1){
            if(arr[i-1] <= j)  dp[i][j] = dp[i-1][j-arr[i-1]] | dp[i-1][j];
            else    dp[i][j] = dp[i-1][j];
        }
    }
    cout<<((dp[n][sum]) ? 1 : 0)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int arr[n];
    fr(i, 0, n) cin>>arr[i];
    int sum;
    cin>>sum;
    solve(n, arr, sum);

    return 0;
}