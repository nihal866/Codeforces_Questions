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
    int n;
    cin>>n;
    int a, b, c, a1, b1, c1, sum = 0;
    cin>>a>>b>>c;
    a1 = a;
    b1 = b;
    c1 = c;
    string s;
    cin>>s;
    fri(i, 0, n){
        if(s[i] == 'P') sum += ((c>0)?1:0), c--;
        else if(s[i] == 'R')    sum += ((b>0)?1:0), b--;
        else if(s[i] == 'S')    sum += ((a>0)?1:0), a--;
        else    continue;
    }
    if(sum <= (n-1)/2){
        cout<<"NO"<<endl;
        return;
    }
    a = a1;
    b = b1;
    c = c1;
    cout<<"YES"<<endl;
    fri(i, 0, n){
        if(s[i] == 'P'){
            if(c>0) s[i]='S',   c--;
            else    s[i] = 'A';
        }
        else if(s[i] == 'R'){
            if(b>0) s[i]='P',   b--;
            else    s[i] = 'A';
        }
        else if(s[i] == 'S'){
            if(a>0) s[i]='R',   a--;
            else    s[i] = 'A';
        }
    }
    fri(i, 0, n){
        if(s[i] == 'A'){
            if(a>0) s[i]='R',   a--;
            else if(b>0)    s[i]='P',   b--;
            else    s[i]='S';
        }
    }
    cout<<s<<endl;
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