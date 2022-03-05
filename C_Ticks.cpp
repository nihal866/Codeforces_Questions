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

char mat[20][20];
int gye[20][20];
int n, m, k;

int solvel(int i, int j){
    int count = 0;
    while(i>0 && j>0){
        if(mat[i][j] == '*')    count++,    i--,    j--;
    }
    return count;
}
int solver(int i, int j){
    int count = 0;
    while(i>0 && j<n){
        if(mat[i][j] == '*')    count++,    i--,    j++;
    }
    return count;
}

void nd(){
    mem(gye, 0);
    cin>>n>>m>>k;
    fri(i, 0, n){
        fri(j, 0, m)    cin>>mat[i][j];
    }
    bool ans = true;
    fri(i, 0, n){
        fri(j, 0, m){
            if(mat[i][j]=='*'){
                if(solvel(i, j) == solver(i, j)){
                    if(solvel(i, j) < k){
                        cout<<"NO"<<endl;
                        return;
                    }
                }
            }
        }
    }
    cout<<"YES"<<endl;
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