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


void nd(){
    ll a, s;
    cin>>a>>s;
    string b = "";
    while(a && s){
        int n = a % 10;
        a = a / 10;
        int m = s % 10;
        if(m >= n){
            b = to_string((s % 10) - n) + b;
            s = s/10;
        }
        else{
            if((s%100) - n > 9 || (s%100) - n < 0){
                cout<<-1<<endl;
                return;
            }
            b = to_string((s % 100) - n) + b;
            s = s/100;
        }
    }
    if(a){
        cout<<-1<<endl;
        return;
    }
    if (s)  b = to_string(s) + b;
    ll posi = 0; 
    string ans1 = "";
    for(ll i = 0; i < b.size(); i++) {
    if (b[i] != '0') {
      posi = i;
      break;
    }
    }
    for (ll i = posi; i < b.size(); i++)   ans1 += b[i];
    cout << ans1 << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
  //  preCalculatorPrime();
    cin>>t;
    while(t--){
        nd();
    }
    return 0;
}
