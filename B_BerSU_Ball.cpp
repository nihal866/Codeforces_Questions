#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fri(i, a, b) for(ll i = a; i < b; i++)
#define frd(i, a, b) for(ll i = a; i >= b; i--)
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


const long long M = 1e9 + 7;
long long mod(long long x){
    return ((x%M + M)%M);
}


long long add(long long a, long long b){
    return mod(mod(a) + mod(b));
}


long long mul(long long a, long long b){
    return mod(mod(a) * mod(b));
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
    int boys[n];
    fri(i, 0, n)    cin>>boys[i];
    int m;
    cin>>m;
    int girls[m];
    priority_queue<int> p1, p2;
    fri(i, 0, m)    cin>>girls[i],  p1.push(girls[i]);
    int count = 0, nw;
    srt(boys, n);
    frd(i, n-1, 0){
        if(p1.size()==0 && p2.size()==0){
            cout<<count<<endl;
            return;
        }
        if(p1.size()){
            while(p1.size()){
                nw = p1.top();
                p1.pop();
                if(abs(nw-boys[i]) > 1) p2.push(nw);
                else{
                    count++;
                    break;
                }
            }
            while(p1.size()){
                p2.push(p1.top());
                p1.pop();
            }
        }
        else{
            while(p2.size()){
                nw = p2.top();
                p2.pop();
                if(abs(nw-boys[i]) > 1) p1.push(nw);
                else{
                    count++;
                    break;
                }
            }
            while(p2.size()){
                p1.push(p2.top());
                p2.pop();
            }
        }
    }
    cout<<count<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
 //   cin>>t;
    while(t--){
        nd();
    }
    return 0;
}