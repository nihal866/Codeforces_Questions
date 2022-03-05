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

    
    long double a, n, l;
    cin>>n>>l;
    vector<long double> v;
    vector<long double>::iterator itr;
    v.reserve(1001);
    fr(i, 0, n) cin>>a, v.push_back(a);
    srt(v);
    itr = unique(v.begin(), v.end());
    v.resize(distance(v.begin(), itr));
    vector<long double> diff;
    diff.reserve(1000);
    long double d;
    if(v[0] == 0)   d = v[1]/2, diff.push_back(d);
    else    diff.push_back(v[0]);
    fr(i, 2, n) d = (v[i] - v[i-1])/2,  diff.push_back(d);
    diff.push_back((l - v[v.size()-1]));
    srt(diff);
    cout<<std::fixed<<setprecision(10);
    cout<<diff[diff.size()-1]<<endl;

    return 0;
}