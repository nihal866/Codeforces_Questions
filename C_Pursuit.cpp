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
        int n, k;
        cin>>n;
        ll val, m = 0, sa = 0, sb = 0, sumb = 0;
        vector<ll> a;
        vector<ll> b;
        a.reserve(100000);
        b.reserve(100000);
        fr(i, 0, n) cin>>val,   a.push_back(val);
        fr(i, 0, n) cin>>val,   b.push_back(val);
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        k = n - n/4;
        int pb = k, pa = n/4, z = n/4;
        fr(i, 0, k) sa+=a[i];
        fr(i, 0, k) sb+=b[i];
        srt(a);
        if(sa>=sb)  cout<<0<<endl;
        else{
            while(sa<sb){
                n++;
                b.push_back(0);
                a.push_back(100);
                if(n/4 == z)    sb += b[pb++];
                else    sa -= a[pa++];
                sa += 100;
                z = n/4;
                m++;
            }
            cout<<m<<endl;
        }
    }

    return 0;
}