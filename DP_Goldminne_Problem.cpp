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

int arr[52][52];

void solve(int n, int m){
    int gold[n][m];
    memset(gold, 0, sizeof(gold));
    int right, rightup, rightdown;
    for(int j = m-1; j >= 0; j--){
        for(int i = 0; i < n; i++){
            rightup = (i==0 || j==m-1) ? 0 : gold[i-1][j+1];
            right = (j == m-1) ? 0 : gold[i][j+1];
            rightdown = (i==n-1 || j==m-1) ? 0 : gold[i+1][j+1];

            gold[i][j] = arr[i][j] + max3(rightup, right, rightdown);
        }
    }
    int mx = INT_MIN;
    fr(i, 0, n) mx = max(mx, gold[i][0]);
    cout<<mx;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    fr(i, 0, n){
        fr(j, 0, m) cin>>arr[i][j];
    }
    solve(n, m);


    return 0;
}