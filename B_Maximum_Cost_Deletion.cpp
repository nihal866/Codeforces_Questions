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

    int t;
    cin>>t;
    while(t--){
        int n, a, b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        int cnt0 = 1, cnt1 = 1;
        vector<int> v0;
        vector<int> v1;
        fr(i, 0, n-1){
            if(s[i]!=s[i+1]){
                if(s[i] == '1') v1.push_back(cnt1), cnt1 = 1;
                else    v0.push_back(cnt0), cnt0 = 1;
            }  
            else{
                if(s[i] == '1') cnt1++;
                else    cnt0++;
            }
        }
        (s[n-1]=='1') ? v1.push_back(cnt1) : v0.push_back(cnt0);
        int sum0 = 0, sum1 = 0;
        fr(i, 0, v1.size()) sum1 += v1[i];
        fr(i, 0, v0.size()) sum0 += v0[i];

        if(b<0){
            int total = n*a;
            int x = min(v1.size(), v0.size()) + 1;
            total += x*b;
            cout<<total<<endl;
        }
        else cout<<(n*(b+a))<<endl;
    
    }

    return 0;
}