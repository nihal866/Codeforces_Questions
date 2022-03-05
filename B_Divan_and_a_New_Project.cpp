#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define fri(i, a, b) for(int i = a; i < b; i++)
#define frd(i, a, b) for(int i = a; i >= b; i--)
#define g(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/g(a,b)
#define lb(v,key) lower_bound(v.begin(), v.end(), key)
#define ub(v,key) upper_bound(v.begin(), v.end(), key)
#define srtvec(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
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
    vector<pair<int, int>> arr(n);
    fri(i, 0, n)    cin>>arr[i].first,  arr[i].second = i;
    srtvec(arr);
    rev(arr);
    vector<int> ans(n);
    int res = 0;
    int mid = (n+1)/2;
    int left = mid-1, right = mid+1;
    bool l = true;
    fri(i, 0, n){
        int cnt = arr[i].first;
        int idx = arr[i].second;
        int cost = 2;
        if(l)   ans[idx] = left,    cost *= abs(mid - left--);
        else    ans[idx] = right,   cost *= abs(mid - right++);
        res += cnt * cost;
        l = !l;
    }
    cout<<res<<endl;
    cout<<mid<<" ";
    for(auto a : ans)   cout<<a<<" ";
    cout<<endl;
}


signed main(){
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