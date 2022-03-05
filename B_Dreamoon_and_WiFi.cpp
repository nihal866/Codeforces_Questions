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
#define reverse(v) reverse(v.begin(), v.end())
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


long long max3(long long a, long long b, long long c){
    if(a > b)
        return (a > c) ? a : c;
    else
        return (b > c) ? b : c;
}


long long min3(long long a, long long b, long long c){
    if(a < b)
        return (a < c) ? a : c;
    else
        return (b < c) ? b : c;
}


void nd(){
    string s1, s2;
    cin>>s1>>s2;
    int init = 0;
    fri(i, 0, s1.size()){
        if(s1[i] == '+')    init++;
        else    init--;
    }
    int dora = 0, ques = 0;
    fri(i, 0, s1.size()){
        if(s2[i] == '+')    dora++;
        else if(s2[i] == '-')   dora--;
        else    ques++;
    }
    if(!ques){
        if(dora == init)    cout<<1<<endl;
        else    cout<<0<<endl;
        return;
    }
    int dest = abs(dora - init);
    if(dest > ques){
        cout<<0<<endl;
        return;
    }
    int dp[11];
    dp[0] = dp[1] = 1;
    fri(i, 2, 11)   dp[i]=dp[i-1]*i;
    if(ques & 1){
        if(dest%2 == 0){
            cout<<0<<endl;
            return;
        }
        dest = (ques - dest)/2;
        double poss = (dp[ques])/(dp[ques-dest]*dp[dest]);
        double total = 1 << ques;
        cout<<setprecision(9)<<(poss/total)<<endl;
    }
    else{
        if(dest==ques/2 || dest%2==0){
            dest = (ques - dest)/2;
            double poss = (dp[ques])/(dp[ques-dest]*dp[dest]);
            double total = 1 << ques;
            cout<<setprecision(9)<<(poss/total)<<endl;
        }
        else    cout<<0<<endl;
    }
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