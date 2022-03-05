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

void dijkstra(vector<pair<ll, ll>> adj[], vector<ll> &distance, vector<ll> &parent){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        ll curr = pq.top().second;
        ll dist = pq.top().first;
        pq.pop();
        for(auto a : adj[curr]){
            ll wt = a.first;
            ll n = a.second;
            if(dist+wt < distance[n]){
                distance[n] = dist + wt;
                pq.push({distance[n], n});
                parent[n] = curr;
            }
        }
    }
}

void nd(){
    ll n, m;
    cin>>n>>m;
    vector<pair<ll, ll>> adj[n+1];
    vector<ll> parent(n+1, -1);
    parent[1] = 1;
    vector<ll> distance(n+1, 0);
    fri(i, 2, n+1)  distance[i] = 1e13;
    ll u, v, w;
    fri(i, 0, m){
        cin>>u>>v>>w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    dijkstra(adj, distance, parent);
    if(distance[n] == 1e13){
        cout<<-1<<endl;
        return;
    }
    stack<ll> st;
    st.push(n);
    while(n != 1){
        st.push(parent[n]);
        n = parent[n];
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
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