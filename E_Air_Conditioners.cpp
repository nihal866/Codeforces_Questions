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


void nd(){
    int n, k;
    cin>>n>>k;
    int pos[k];
    ll temp[n] = {0}, val;
    fr(i, 0, k) cin>>pos[i];
    ll rooms[n];
    fr(i, 0, k){
        cin>>val;
        temp[pos[i]-1] = val;
    }
    if(temp[n-1])   rooms[n-1]=temp[n-1];
    else    rooms[n-1]=10000000000;
    for(int i = n-2; i >= 0; i--){
        if(temp[i]) rooms[i]=min(temp[i], rooms[i+1]+1);
        else    rooms[i]=rooms[i+1]+1;
    }
    fr(i, 1, n){
        rooms[i] = min(rooms[i], rooms[i-1]+1);
    }
    fr(i, 0, n) cout<<rooms[i]<<" ";
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