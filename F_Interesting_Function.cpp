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


void nd(){
    ll l, r;
    cin>>l>>r;
    int a[10], b[10];
    int i = 9, digits = 0;
    while(r>0){
        digits++;
        a[i] = l % 10;
        l = l / 10;
        b[i] = r % 10;
        r = r / 10;
        i--;
    }
    int ind = 10 - digits;
    ll dp[10] = {0};
    ll sum = (b[ind] > a[ind]) ? (b[ind]-a[ind]) : 0;
    dp[ind] = sum;
    fr(i, ind+1, 10){
        dp[i] = dp[i-1]*10 + (b[i]-a[i]);
        sum += dp[i];
    }
    cout<<sum<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        nd();
    }
    return 0;
}