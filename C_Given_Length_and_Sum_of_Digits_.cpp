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
    int m, s, ind = -1;
    bool poss = true;
    cin>>m>>s;
    int mx[m+1] = {0};
    int mn[m+1] = {0};
    if(s==0){
        if(m==1){
            cout<<"0 0";
            return;
        }
        else{
            cout<<"-1 -1";
            return;
        }
    }
    else{
        fr(i, 1, m+1){
            mx[i] = min(9, s);
            mn[m-i+1] = mx[i];
            s -= mx[i];
        }
        if(s>0){
            cout<<"-1 -1";
            return;
        }
        else{
            int j = 1;
            while(mn[j] == 0)   j++;
            mn[j]--;
            mn[1]++;
        }
    }
    fr(i, 1, m+1) cout<<mn[i];
    cout<<" ";
    fr(i, 1, m+1) cout<<mx[i];
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