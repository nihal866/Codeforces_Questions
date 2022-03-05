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

class DSU{
    private:
        vector<int> parent, size, rank;
    
    public:
        DSU(int n){
            for(int i = 0; i <= n; i++){
                parent.push_back(i);
                size.push_back(1);
                rank.push_back(0);
            }
        }
    
    public:
        int findParent(int node){
            if(parent[node] == node)    return node;
            return parent[node] = findParent(parent[node]);
        }
    
    public:
        void unionSize(int u, int v){
            int pu = findParent(u);
            int pv = findParent(v);
            if(pu == pv)    return;
            if(size[pu] < size[pv]){
                size[pv] += size[pu];
                parent[pu] = pv;
            }
            else{
                size[pu] += size[pv];
                parent[pv] = pu;
            }
        }
        
        void unionRank(int u, int v){
            int pu = findParent(u);
            int pv = findParent(v);
            if(pu == pv)    return;
            if(rank[pu] < rank[pv]){
                parent[pu] = pv;
            }
            else if(rank[pv] < rank[pu]){
                parent[pv] = pu;
            }
            else{
                parent[pv] = pu;
                rank[pu]++;
            }
        }
};

void nd(){
    int n, u, v;
    cin>>n;
    DSU dsu(n+1);
    vector<pair<int, int>> old;
    fri(i, 1, n){
        cin>>u>>v;
        if(dsu.findParent(u) != dsu.findParent(v))  dsu.unionSize(u, v);
        else    old.push_back({u, v});
    }
    set<int> nw;
    fri(i, 1, n+1){
        nw.insert(dsu.findParent(i));
    }
    int x = *(nw.begin());
    nw.erase(x);
    cout<<old.size()<<endl;
    u = 0;
    for(auto a : nw){
        cout<<old[u].first<<" "<<old[u].second<<" "<<x<<" "<<a<<endl;
        u++;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
   // cin>>t;
    while(t--){
        nd();
    }
    return 0;
}