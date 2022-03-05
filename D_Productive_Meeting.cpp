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
    priority_queue<pair<ll, ll>> pq;
    int n;
    cin>>n;
    ll arr[n];
    vector<vector<ll>> ans;
    vector<ll> g;
    ll x = 1, n1, ind1, n2, ind2;
    fri(i, 0, n)    cin>>arr[i];
    fri(i, 0, n){
        if(arr[i])  pq.push({arr[i], i});
    }
    while(!pq.empty()){
        n1 = pq.top().first;
        ind1 = pq.top().second;
        pq.pop();
        n2 = pq.top().first;
        ind2 = pq.top().second;
        pq.pop();
        g.clear();
        g.push_back(ind1+1);
        g.push_back(ind2+1);
        ans.push_back(g);
        if(n1 > 1)  pq.push({n1-1, ind1});
        if(n2>1)    pq.push({n2-1, ind2});
    }
    cout<<ans.size()<<endl;
    fri(i, 0, ans.size()){
        fri(j, 0, ans[i].size())    cout<<ans[i][j]<<" ";
        cout<<endl;
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