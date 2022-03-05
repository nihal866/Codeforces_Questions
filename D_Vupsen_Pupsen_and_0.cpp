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
int mod(int x){	return ((x%M + M)%M); }
int add(int a, int b){	return mod(mod(a) + mod(b)); }
int mul(int a, int b){	return mod(mod(a) * mod(b)); }
int max3(int a, int b, int c){
    if(a > b)	return (a > c) ? a : c;
    else	return (b > c) ? b : c; }
int min3(int a, int b, int c){
    if(a < b)	return (a < c) ? a : c;
    else	return (b < c) ? b : c; }
    
void nd(){
    int n;
    cin>>n;
    vll arr(n), ans(n);
    fri(i, 0, n)    cin>>arr[i];
    if(n & 1){
        if(arr[0]+arr[1] != 0){
            ans[2] = (arr[0] + arr[1]);
            ans[0] = ans[1] = -1*arr[2];
        }
        else if(arr[1]+arr[2] != 0){
            ans[0] = (arr[1] + arr[2]);
            ans[2] = ans[1] = -1*arr[0];
        }
        else{
            ans[1] = (arr[0]+arr[2]);
            ans[0] = ans[2] = -1*arr[1];
        }
        fri(i, 3, n){
            ans[i] = -1*arr[i+1];
            ans[i+1] = arr[i];
            i++;
        }
    }
    else{
        fri(i, 0, n){
            ans[i] = -1*arr[i+1];
            ans[i+1] = arr[i];
            i++;
        }
    }
    for(auto a : ans)   cout<<a<<" ";
    cout<<endl;
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