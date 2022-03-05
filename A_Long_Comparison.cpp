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
    
int digits(int x){
    int count = 0;
    while(x)    x /= 10,    count++;
    return count;
}

void nd(){
    int n1, n2, z1, z2;
    cin>>n1>>z1>>n2>>z2;
    while(n1%10 == 0)   z1++,   n1/=10;
    while(n2%10 == 0)   z2++,   n2/=10;
    if(n1==n2 && z1==z2){
        cout<<"="<<endl;
        return;
    }
    while(digits(n1) != digits(n2)){
        if(n1 < n2) n1*=10, z1--;
        else    n2*=10, z2--;
    }
    if(n1 < n2){
        if(z1>z2)   cout<<">"<<endl;
        else    cout<<"<"<<endl;
    }
    else{
        if(z2>z1)   cout<<"<"<<endl;
        else    cout<<">"<<endl;
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