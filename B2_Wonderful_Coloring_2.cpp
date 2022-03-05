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
    ll n, k, m;
    cin>>n>>k;
    ll ans[n], color[k+1] = {0};
    unordered_map<ll, vector<ll>> mp;
    fr(i, 0, n){
        cin>>m;
        mp[m].push_back(i);
    }
    ll col = 0, col1, x = 0, y = 0;
    for(auto &a:mp){
        if(a.second.size() >= k){
            x++;
            fr(i, 0, k) ans[a.second[i]]=i+1;
            fr(i, k, a.second.size()) ans[a.second[i]]=0;
        }
        else{
            y += a.second.size();
            fr(i, 0, a.second.size()){
                col1 = (col++) % k;
                col1++;
                ans[a.second[i]] = col1;
            }
        }
    }
    int how = x + y/k;
    fr(i, 0, n){
        color[ans[i]]++;
        if(color[ans[i]] <= how)  cout<<ans[i]<<" ";
        else    cout<<"0 ";
    }
    cout<<endl;
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