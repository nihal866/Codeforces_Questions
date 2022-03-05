#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,a,b) for(int i = a; i < b; i++)
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
    vector<pair<int, int> > v;
    v.reserve(10000);
    while(t--){
        int n;
        cin>>n;
        int a[n], b[n], diff[n];
        int s1 = 0, s2 = 0;
        for(int i = 0; i < n; i++) cin>>a[i],  s1 += a[i];
        for(int i = 0; i < n; i++) cin>>b[i],  s2 += b[i];
        if(s1 != s2)    cout<<-1<<endl;
        //else if(n == 1) cout<<0<<endl;
        else{
            for(int i = 0; i < n; i++) diff[i] = (a[i] - b[i]);
            int x[100], y[100], j = 0, k = 0, cnt = 0;
            for(int i = 0; i < n; i++){
                if(!diff[i])    continue;
                if(diff[i] > 0){
                    cnt += diff[i];
                    while(diff[i]--)    x[j++] = i+1;
                }
                else if(diff[i] < 0){
                    diff[i] = abs(diff[i]);
                    while(diff[i]--)    y[k++] = i+1;
                }
                
            }
            cout<<cnt<<endl;
            for(int i = 0; i < cnt; i++)  cout<<x[i]<<" "<<y[i]<<endl;
        }
    }
 
    return 0;
}