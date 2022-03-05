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
    ll x = 0, nxr, mxr, arr[n];
    fri(i, 0, n){
        cin>>arr[i];
        x = x^arr[i];
    }
    nxr = x;
    mxr = 0;
    fri(i, 1, n){
        mxr = mxr ^ arr[i-1];
        nxr = nxr ^ arr[i-1];
        if(mxr==nxr){
            cout<<"YES"<<endl;
            return;
        }
    }
    mxr = 0;
    nxr = x;
    fri(i, 0, n-1){
        mxr ^= arr[i];
        nxr ^= arr[i];
        ll nxx = 0, mxx = nxr;
        fri(j, i+1, n-1){
            mxx ^= arr[j];
            nxx ^= arr[j];
            if(mxx==nxx && mxx==mxr){
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
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