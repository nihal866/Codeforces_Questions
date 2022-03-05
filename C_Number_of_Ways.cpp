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
    ll arr[n], sum[n+1] = {0};
    fri(i, 0, n)    cin>>arr[i],    sum[i+1] = sum[i] + arr[i];
    if(sum[n]%3 || n<3){
        cout<<0<<endl;
        return;
    }
    if(sum[n] == 0){
        ll zero = 0;
        fri(i, 1, n+1){
            if(sum[i] == 0) zero++;
        }
        if(zero < 3){
            cout<<0<<endl;
            return;
        }
        zero--;
        cout<<((zero-1)*zero)/2<<endl;
        return;
    }
    queue<ll> ones;
    ll a = sum[n]/3;
    ll b = a*2;
    ll suff[n+1] = {0};
    frd(i, n-1, 0){
        suff[i] = suff[i+1];
        if(sum[i+1] == b)   suff[i]++;
        if(sum[i+1] == a)   ones.push(i);
    }
    ll ans = 0, ind;
    while(!ones.empty()){
        ind = ones.front();
        ones.pop();
        ans += suff[ind];
    }
    cout<<ans<<endl;
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