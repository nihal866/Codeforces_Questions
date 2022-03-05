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

void solve(map<pair<int, int>, int>& mp, map<pair<int, int>, int>& ans, int s, int e){
    if(s == e){
        ans[{s, e}] = s;
        return;
    }
    fri(i, s, e+1){
        if(i == s){
            if(mp.count({i+1, e})){
                ans[{s, e}] = i;
                solve(mp, ans, i+1, e);
                return;
            }
        }
        else if(i == e){
            if(mp.count({s, i-1})){
                ans[{s, e}] = i;
                solve(mp, ans, s, i-1);
                return;
            }
        }
        else{
            if(mp.count({s, i - 1}) && mp.count({i + 1, e})){
                ans[{s, e}] = i;
                solve(mp, ans, s, i - 1);
                solve(mp, ans, i + 1, e);
                return;
            }
        }
    }
}

void nd(){
    int n;
    cin>>n;
    vector<pair<int, int>> v(n);
    map<pair<int, int>, int> mp;
    map<pair<int, int>, int> ans;
    fri(i, 0, n){
        cin>>v[i].first>>v[i].second;
        //v[i].first = v[i].second.second - v[i].second.first;
        mp[{v[i].first, v[i].second}]++;
    }
    solve(mp, ans, 1, n);
    for(auto a : mp){
        if(ans.count(a.first)){
            cout<<a.first.first<<" "<<a.first.second<<" "<<ans[a.first]<<endl;
        }
    }
    cout<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
 //   preCalculatorPrime();
    cin>>t;
    while(t--){
        nd();
    }
    return 0;
}


