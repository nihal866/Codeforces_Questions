#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i, a, b) for(int i = a; i < b; i++)

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

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    vector<ll> v;
    v.reserve(100000);
    cin>>t;
    while(t--){
        int k, n, m;
        bool mc = true;
        cin>>k>>n>>m;
        int a[n], b[m], arr[n+m], i = 0, j = 0, c = 0;
        fr(i, 0, n) cin>>a[i];
        fr(i, 0, m) cin>>b[i];
        while(i<n || j<m){
            int o = 0;
            while(i<n && a[i]<=k){
                k += !a[i];
                arr[c++] = a[i];
                i++;
                o = 1;
            }
            while(j<m && b[j]<=k){
                k += !b[j];
                arr[c++] = b[j];
                j++;
                o = 1;
            }
            if(!o){
                cout<<-1<<endl;
                mc = false;
                break;
            }
        }
        if(mc){
            for(int i = 0; i < c; i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
