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
    // n 1 phla haarega
    // n odd dusra harega
    ll n;
    cin>>n;
    if(n == 1){
        cout<<"FastestFinger"<<endl;
        return;
    }
    if(n == 2){
        cout<<"Ashishgup"<<endl;
        return;
    }
    if(n & 1){
        cout<<"Ashishgup"<<endl;
        return;
    }
    // n even hua to agar ek bhi odd divisor nhi hua to phla haar jayega 
    fri(i, 2, 60){
        if((1 << i) == n){
            cout<<"FastestFinger"<<endl;
            return;
        }
    }
    // n me kitne 2 hain
    int even = 0;
    while(n%2 == 0){
        even++;
        n /= 2;
    }
    int odd = 0;
    for(ll i = 3; i*i <= n; i++){
        while(n%i == 0){
            odd++;
            n /= i;
        }
    }
    if(n > 1)   odd++;
    if(even == 1){
        if(odd > 1) cout<<"Ashishgup"<<endl;
        else    cout<<"FastestFinger"<<endl;
    }
    else    cout<<"Ashishgup"<<endl;
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