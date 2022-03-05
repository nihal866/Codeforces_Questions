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
    
bool check(vector<vll>& arr, int pos){
    fri(i, 0, arr[0].size()){
        if(arr[pos][i] != arr[pos-1][i])    return false;
    }
    return true;
}

void nd(){
    int n;
    cin>>n;
    map<int, int> mp;
    //int arr[n][n];
    vector<vector<int>> arr(2005, vector<int>(n));
    //cout<<arr.size()<<" "<<arr[0].size()<<endl;
    fri(i, 0, n)    cin>>arr[0][i];
    // fri(i, 0, n)    cout<<arr[0][i];
    fri(i, 0, n)    mp[arr[0][i]]++;
    //fri(i, 0, n)    cout<<arr[0][i]<<"ele ";
    int pos = n-1;
    fri(i, 1, 2005){
        fri(j, 0, n)    arr[i][j] = mp[arr[i-1][j]];
        if(check(arr, i)){
            pos = i-1;
            break;
        }
        mp.clear();
        fri(j, 0, n)    mp[arr[i][j]]++;
    }
    int q;
    cin>>q;
    while(q--){
        int idx, turn;
        cin>>idx>>turn;
        if(turn > pos)  cout<<arr[pos][idx-1]<<endl;
        else    cout<<arr[turn][idx-1]<<endl;
    }
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