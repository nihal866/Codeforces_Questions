#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i, a, b) for(int i = a; i < b; i++)
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

    string a, b;
    cin>>a>>b;
    set<string> s;
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    s.insert(a);
    s.insert(b);
    if(s.size() == 1)   cout<<0<<endl;
    else{
        auto itr = s.begin();
        if(*itr == a)   cout<<-1<<endl;
        else    cout<<1<<endl;
    }

    return 0;
}