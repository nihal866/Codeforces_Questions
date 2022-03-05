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
    ll mx, ans1=INT_MAX, ans2=INT_MAX, W, H, x1, y1, x2, y2, w, h;
    cin>>W>>H>>x1>>y1>>x2>>y2>>w>>h;
    bool cond1 = (abs(x2-x1)+w <= W) ? true : false;
    bool cond2 = (abs(y2-y1)+h <= H) ? true : false;
    if(cond1 || cond2){
        if(cond1){
            mx = max(x1, W-x2);
            ans1 = (mx>=w) ? 0 : w-mx;
        }
        if(cond2){
            mx = max(y1, H-y2);
            ans2 = (mx>=h) ? 0 : h-mx;
        }
        cout<<min(ans1, ans2)<<endl;
    }
    else    cout<<-1<<endl;
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