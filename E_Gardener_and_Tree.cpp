#include <bits/stdc++.h>



using namespace std;
typedef long long ll;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll tt;
    cin >> tt;
    while(tt--) {
        ll n;
        cin >> n;
        ll k;
        cin >> k;
        map<ll,set<ll>> adj;
        vector<ll> a(n,0);
        for(ll i=0; i<n-1; i++) {
            ll u,v;
            cin>>u>>v;
            adj[u-1].insert(v-1);
            adj[v-1].insert(u-1);
            a[u-1]++;
            a[v-1]++;
        }
        queue<ll> q;
        ll visited[n];
        for(ll i=0; i<n; i++) {
            visited[i]=0;
            if(a[i]==1 || a[i]==0) {
                visited[i]=1;
                q.push(i);
            }
        }
        ll res=n;
        while(res>0 && k>0) {
            queue<ll> q1;
            while(q.size()>0) {
                res--;
                ll x=q.front();
                q.pop();
                for(auto i:adj[x]) {
                    a[i]--;
                    if(a[i]==1 || a[i]==0 && visited[i]==0) {
                        visited[i]=1;
                        q1.push(i);
                    }
                }
            }
            q=q1;
            k--;
        }
        cout<<res<<'\n';
    }
    return 0;
}