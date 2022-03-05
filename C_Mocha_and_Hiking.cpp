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

void nd(){
    int n, val;
    cin>>n;
    int arr[n], ans[n+1] = {0};
    bool zero = false;
    fri(i, 0, n){
        cin>>arr[i];
        if(arr[i] == 0) zero = true;
    }
    if(!zero){
        cout<<n+1<<" ";
        fri(i, 1, n+1)  cout<<i<<" ";
        cout<<endl;
    }
    else{
        bool poss = false;
        frd(i, n-1, 0){
            if(arr[i] == 0){
                ans[i+1] = n+1;
                ans[i] = i+1;
                poss = true;
            }
            if(poss){
                break;
            }
            ans[i+1] = i+1;
        }
        fri(i, 0, n+1){
            if(ans[i] == 0) cout<<i+1<<" ";
            else    cout<<ans[i]<<" ";
        }
        cout<<endl;;
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