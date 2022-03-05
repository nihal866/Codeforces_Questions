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
#define pb push_back


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

vector<ll> adj[200001];
ll dist[200001], dist2[200001];
bool visited[200001];


void nd(){
     ll n, k;
        cin >> n >> k;


        for(int i = 1; i <= n; i++){
            dist[i] = dist2[i] = 100000000;
            visited[i] = false;
            adj[i].clear();
        }

        queue<ll> q;
        for(int i = 0; i < k; i++){
            ll val;
            cin >> val;
            q.push(val);
            visited[val] = true;
            dist[val] = 0;
        }

        for(int i = 0; i < n-1; i++){
            ll a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }


        while(!q.empty()){
            ll curr = q.front();
            q.pop();
            for(auto x: adj[curr]){
                if(!visited[x]){
                    visited[x] = true;
                    q.push(x);
                    dist[x] = min(dist[x], 1 + dist[curr]);
                }
            }
        }

        queue<ll> q2;
        q2.push(1);

        for(int i = 1; i <= n; i++){
            visited[i] = false;
        }

        visited[1] = true;
        dist2[1] = 0;

        bool done = false;

        while(!q2.empty() or done){
            ll curr = q2.front();
            q2.pop();
            if(curr != 1 and adj[curr].size() == 1){
                done = true;
                break;
            }
            for(auto x: adj[curr]){
                if(!visited[x]){
                    visited[x] = true;
                    dist2[x] = min(1 + dist2[curr], dist2[x]);
                    if(dist2[x] >= dist[x]){
                        continue;
                    }
                    q2.push(x);
                }
            }
        }
        
        if(done){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }




    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    preCalculatorPrime();
    cin>>t;
    while(t--){
        nd();
    }
    return 0;
}