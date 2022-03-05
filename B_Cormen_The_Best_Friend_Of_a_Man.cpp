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
    int n, k;
    cin>>n>>k;
    int arr[n];
    fri(i, 0, n)    cin>>arr[i];
    int dp[n];
    int count;
    int ans1 = 0;
    dp[0] = arr[0];
    fri(i, 1, n){
        count = 0;
        if(dp[i-1]+arr[i] < k)  count=abs(k-(dp[i-1]+arr[i]));
        dp[i] = arr[i]+count;
        ans1 += count;
    }
    int pd[n];
    int ans2 = 0;
    pd[n-1] = arr[n-1];
    frd(i, n-2, 0){
        count = 0;
        if(pd[i+1]+arr[i] < k)  count=abs(k-(pd[i+1]+arr[i]));
        pd[i] = arr[i]+count;
        ans2 += count;
    }
    if(ans1 <= ans2){
        cout<<ans1<<endl;
        fri(i, 0, n)    cout<<dp[i]<<" ";
        cout<<endl;
    }
    else{
        cout<<ans2<<endl;
        fri(i, 0, n)    cout<<pd[i]<<" ";
        cout<<endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
 //   cin>>t;
    while(t--){
        nd();
    }
    return 0;
}