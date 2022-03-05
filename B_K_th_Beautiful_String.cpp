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
    cin>>t;;
    while(t--){
        ll n, k;
        cin>>n>>k;
        vector<ll> v;
        v.reserve(200000);
        v.push_back(0);
        v.push_back(1);
        fr(i, 2, n+1) v.push_back(v[i-1] + i);
        auto itr = lb(v, k);
        int r = (itr - v.begin());
        int pos1 = n - r - 1;
        int l = v[r] - k;
        int pos2 = pos1 + l + 1;
        string s = "";
        fr(j, 0, n){
            if(j==pos1 || j==pos2)   s.push_back('b');
            else    s.push_back('a');
        }
        cout<<s<<endl;
    }

    return 0;
}