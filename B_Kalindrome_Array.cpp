#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define fri(i, a, b) for(int i = a; i < b; i++)
#define frd(i, a, b) for(int i = a; i >= b; i--)
#define g(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/g(a,b)
#define vll vector<int>
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
        for(int j = i*i; j < N; j=j+i)	isPrime[j] = false; }
    for(int i = 2; i < N; i++){
        if(isPrime[i])	s.insert(i); }}
const long long M = 1e9 + 7;
long long mod(long long x){	return ((x%M + M)%M); }
long long add(long long a, long long b){	return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b){	return mod(mod(a) * mod(b)); }
long long max3(long long a, long long b, long long c){
    if(a > b)	return (a > c) ? a : c;
    else	return (b > c) ? b : c; }
long long min3(long long a, long long b, long long c){
    if(a < b)	return (a < c) ? a : c;
    else	return (b < c) ? b : c; }
    
bool check(vll& changed){
    int l = 0, r = changed.size()-1;
    while(l <= r){
        if(changed[l] != changed[r])    return false;
        l++, r--;
    }
    return true;
}

void nd(){
    int n,x;
    cin>>n;
    vll arr(n);
    fri(i, 0, n)    cin>>arr[i];
    int l = 0, r = n-1;
    while(l < r){
        if(arr[l] == arr[r]){
            l++;
            r--;
            continue;
        }
        break;
    }
    if(arr[l] == arr[r]){
        cout<<"YES"<<endl;
        return;
    }
    vll changed;
    changed.reserve(n);
    fri(i, 0, n){
        if(arr[i] != arr[l])   changed.push_back(arr[i]);
    }
    if(check(changed)){
        cout<<"YES"<<endl;
        return;
    }
    changed.clear();
    //val = arr[r];
    fri(i, 0, n){
        if(arr[i] != arr[r])   changed.push_back(arr[i]);
    }
    if(check(changed)){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}
    
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        nd();
    }
    return 0;
}