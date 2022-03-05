#include <bits/stdc++.h>
#define int long long
#define float double
#define sz 100005
#define all(a) a.begin(), a.end()
#define mod 1000000007
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define debug cout << "here" << endl;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int, int>
using namespace std;
 
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
 
void enumerateSubmasks(int m)
{
    // visits submasks without repetition and in descending order
    for (int s = m;; s = (s - 1) & m)
    {
 
        if (s == 0)
        {
            //...
            break;
        }
    }
}
 
int mpow(int a, int b, int m)
{
    if (b == 0)
        return 1;
    int x = mpow(a, b / 2, m);
    x = (x * x) % m;
    if (b % 2)
    {
        x = (x * a) % m;
    }
    return x;
}
 
void printBinaryString(int n)
{
    vi temp;
    while (n)
    {
        if (n & 1)
            temp.pb(1);
        else
            temp.pb(0);
        n = n >> 1;
    }
    reverse(temp.begin(), temp.end());
    for (auto node : temp)
        cout << node << " ";
    cout << endl;
}
 
void readVector(vi &a)
{
    int n = a.size();
    rep(i, n) cin >> a[i];
}
 
 
int update(int s,int e,int qs,int qe,vi &seg,vi &lazy,int index){
    if(lazy[index]!=-1){
        seg[index] = 1;
        if(s!=e){
 
        }
 
        lazy[index] = -1;
 
    }
 
    if(qs > e || qe < s) {
 
    }
 
    if(s >= qs && e <= qe){
 
    }
 
    int mid = (s+e)/2;
 
    update(s,mid,qs,qe,seg,lazy,2*index);
    update(s,mid,qs,qe,seg,lazy,2*index+1);
 
}
 
 
//vi primes;
//vi primesVisited(sz,-1);
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
//    for(int i = 2 ; i < sz ; i++){
//        if(primesVisited[i]!=-1) continue;
//        primes.pb(i);
//        primesVisited[i] = i;
//        for(int j = i*i ; j < sz ; j+=i) {
//            if(primesVisited[j]==-1) primesVisited[j] = i;
//        }
//    }
 
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<pi> cave;
        rep(i,n){
            int k;
            cin >> k;
            vi arr(k);
            readVector(arr);
            rep(i,k) arr[i]-=i;
            int me = INT_MIN;
            for(auto node : arr) me = max(me,node);
            cave.pb({me,k});
        }
        sort(all(cave));
 
        int s = 1;
        int e = 2e9;
        int answer = e;
        while(s<=e){
            int mid = (s+e)/2;
            int currPower = mid;
            bool can = true;
            for(auto node : cave){
                if(currPower <= node.ff){
                    can = false;
                    break;
                }
                currPower += node.ss;
            }
            if(can){
                answer = mid;
                e = mid-1;
            }else s = mid+1;
        }
        cout << answer << endl;
    }
}