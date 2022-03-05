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

bool lft(string s, int i, string t, int j){
    if(j == t.size())   return true;
    if(s[i] != t[j])    return false;
    if(i < 0)  return false;
    
    return lft(s, i-1, t, j+1);
}

bool rgt(string s, int i, string t, int j){
    if(j == t.size())   return true;
    if(s[i] != t[j])    return false;
    if(i == s.size())   return false;
    
    return (rgt(s, i+1, t, j+1) | lft(s, i-1, t, j+1));
}

void nd(){
    string s, t;
    cin>>s>>t;
    if(s==t){
        cout<<"YES"<<endl;
        return;
    }
    else{
        fr(i, 0, s.size()){
            if(s[i] == t[0]){
                if(rgt(s, i, t, 0)){
                    cout<<"YES"<<endl;
                    return;
                }
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