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

int u, r, l, d, px, py;
void nd(){
    u = 0;
    r = 0;
    l = 0;
    d = 0;
    cin>>px>>py;
    string s;
    cin>>s;
    int n = s.size();
    fr(i, 0, n){
        if(s[i] == 'U') u++;
        else if(s[i] == 'D') d++;
        else if(s[i] == 'R') r++;
        else if(s[i] == 'L') l++;
    }
    if(px>=0 && py>=0){
        if(u>=py && r>=px)  cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;        
    }
    else if(px>=0 && py<=0){
        if(d>=abs(py) && r>=px)  cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;        
    }
    else if(px<=0 && py>=0){
        if(u>=py && l>=abs(px))  cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;        
    }
    else if(px<=0 && py<=0){
        if(d>=abs(py) && l>=abs(px))  cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;        
    }
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