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

void red(ll n){
    fri(i, 0, n){
        if(i%2) cout<<'R';
        else    cout<<'B';
    }
    return;
}

void blue(ll n){
    fri(i, 0, n){
        if(i%2) cout<<'B';
        else    cout<<'R';
    }
    return;
}

string modify(string s, int i){
    string nw = "";
    while(i < s.size()){
        if(s[i] != '?'){
            nw += s[i];
            i++;
            continue;
        }
        if(s[i-1]=='B'){
            nw = nw + 'R';
            s[i] = 'R';
        }
        else if(s[i-1]=='R'){
            nw = nw + 'B';
            s[i] = 'B';
        }
        i++;
    }
    return nw;
}

void nd(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i = 0;
    while(s[i]=='?' && i<n) i++;
    if(i == n){
        fri(i, 0, n){
            if(i%2) cout<<"B";
            else    cout<<"R";
        }
        cout<<endl;
        return;
    }
    else if(i){
        if(s[i]=='B'){
            if(i%2) blue(i);
            else    red(i);
        }
        else{
            if(i%2) red(i);
            else    blue(i);
        }
    }
    string ns = modify(s, i);
    cout<<ns<<endl;
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