#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i, a, b) for(int i = a; i < b; i++)
#define g(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/g(a,b)
#define lb(v,key) lower_bound(v.begin(), v.end(), key)
#define ub(v,key) upper_bound(v.begin(), v.end(), key)
#define srt(v) sort(v.begin(), v.end())
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

ll a, b;
vector<ll> v;

bool dfs(ll n){
    if(n > b)   return false;
    if(n == b)  return true;
    if(dfs(n*2))    v.push_back(2*n);
    else if(dfs((10*n)+1))  v.push_back(10*n + 1);
    else    return false;
    return true;
}

void nd(){
    cin>>a>>b;
    if(a > b){
        cout<<"NO"<<endl;
    }
    else if(a == b){
        cout<<"YES"<<endl<<2<<endl<<a<<" "<<b<<endl;
    }
    else{
        if(dfs(a)){
            v.push_back(a);
            cout<<"YES"<<endl<<v.size()<<endl;
            reverse(v.begin(), v.end());
            fr(i, 0, v.size())  cout<<v[i]<<" ";
        }
        else    cout<<"NO"<<endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--){
        nd();
    }
    return 0;
}