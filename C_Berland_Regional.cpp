#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fri(i, a, b) for(int i = a; i < b; i++)
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


void nd(){
    int n;
    cin>>n;
    ll u[n], sk, sum;
    set<int> st;
    map<int, vector<ll>> mp;
    fri(i, 0, n)    cin>>u[i],  st.insert(u[i]);
    fri(i, 0, n){
        cin>>sk;
        mp[u[i]].push_back(sk);
    }
    vector<ll> sm[n+1];
    for(auto i : mp){
        srtvec(i.second);
        sum = 0;
        sm[i.first].push_back(0);
        fri(j, 0, i.second.size()){
            sum += i.second[j];
            sm[i.first].push_back(sum);
        }
    }
    fri(i, 1, n+1){
        auto itr = st.begin();
        ll moves = 0, sz;
        while(itr != st.end()){
            sz = sm[*itr].size() - 1;
            moves += sm[*itr][sz];
            moves -= sm[*itr][sz%i];
            itr++;
        }
        cout<<moves<<" ";
    }
    cout<<endl;
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