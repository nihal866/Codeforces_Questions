#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fri(i, a, b) for(ll i = a; i < b; i++)
#define frd(i, a, b) for(int i = a; i >= b; i--)
#define g(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/g(a,b)
#define lb(v,key) lower_bound(v.begin(), v.end(), key)
#define ub(v,key) upper_bound(v.begin(), v.end(), key)
#define srtvec(v) sort(v.begin(), v.end())
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
int t;
int m;

void nd(){
    int n;
    cin>>n;
    string arr;
    cin>>arr;
    ll pre[n] = {0}, frw[n] = {0};
    if(arr[0] == '0') pre[0] = 100000000;
    if(arr[n-1] == '0')   frw[n-1] = 100000000;
    fri(i, 1, n){
        if(arr[i] == '0'){
            pre[i] = pre[i-1] + 1;
        }
    }
    frd(i, n-2, 0){
        if(arr[i] == '0'){
            frw[i] = frw[i+1] + 1;
           }
    }
    ll sum = 0;
    fri(i, 0, n){
        sum += min(pre[i], frw[i]);
    }
    cout<<"Case #"<<(m-t)<<": "<<sum<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    m = t;
    while(t--){
        nd();
    }
    return 0;
}