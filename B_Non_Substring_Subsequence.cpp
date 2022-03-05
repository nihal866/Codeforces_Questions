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
    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    int left[2][n+1];
    left[0][0] = left[1][0] = 0;
    fri(i, 1, n+1){
        left[0][i] = left[0][i-1];
        left[1][i] = left[1][i-1];
        if(s[i-1] == '0')   left[0][i]++;
        else    left[1][i]++;
    }
    int right[2][n+1];
    right[0][n] = right[1][n] = 0;
    frd(i, n-1, 0){
        right[0][i] = right[0][i+1];
        right[1][i] = right[1][i+1];
        if(s[i] == '0') right[0][i]++;
        else    right[1][i]++;
    }
    int l, r;
    while(q--){
        cin>>l>>r;
        int m;
        bool poss = false;
        if(s[l-1] == '0'){
            if(left[0][l] > 1){
                cout<<"YES"<<endl;
                continue;
            }
        }
        else{
            if(left[1][l] > 1){
                cout<<"YES"<<endl;
                continue;
            }
        }
        if(s[r-1] == '0'){
            if(right[0][r-1] > 1){
                cout<<"YES"<<endl;
                continue;
            }
        }
        else{
            if(right[1][r-1] > 1){
                cout<<"YES"<<endl;
                continue;
            }
        }
        cout<<"NO"<<endl;    
    }
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