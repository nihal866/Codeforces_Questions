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
    ll n, m;
    cin>>n;
    m = n;
    vector<ll> pq;
    while(n%2 == 0){
        n /= 2;
        pq.push_back(2);
    }
    for(ll i = 3; i*i <= n; i+=2){
        while(n%i == 0){
            n = n/i;
            pq.push_back(i);
        }
    }
    if(n>1) pq.push_back(n);
    //cout<<pq.size()<<endl;
    if(pq.size() < 3){
        cout<<"NO"<<endl;
        return;
    }
    ll a, b, c;
    a = pq[0];
    if(pq[1] == pq[0])  b = pq[1]*pq[2];
    else    b = pq[1];
    c = m / (a*b);
    if(c!=b && c!=a && c>1){
        cout<<"YES"<<endl;
        cout<<a<<" "<<b<<" "<<c<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
        return;
    }
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