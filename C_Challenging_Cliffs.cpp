#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i, a, b) for(int i = a; i < b; i++)
#define g(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/g(a,b)
#define lb(v,key) lower_bound(v.begin(), v.end(), key)
#define ub(v,key) upper_bound(v.begin(), v.end(), key)
#define srt(v) sort(v.begin(), v.end())


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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> v;
        v.reserve(200000);
        ll a, diff;
        fr(i, 0, n) cin>>a, v.push_back(a);
        vector<ll> diff1;
        vector<ll> diff2;
        diff1.reserve(200000);
        diff2.reserve(200000);
        srt(v);
        fr(i, 1, n){
            diff = v[i] - v[i-1];
            diff1.push_back(diff);
            diff2.push_back(diff);
        }
        srt(diff2);
        int pos;
        fr(i, 0, diff1.size()){
            if(diff1[i] == diff2[0]){
                pos = i;
                break;
            }
        }
        cout<<v[pos]<<" ";
        fr(i, pos+2, n) cout<<v[i]<<" ";
        fr(i, 0, pos) cout<<v[i]<<" ";
        cout<<v[pos+1]<<endl;
    }

    return 0;
}