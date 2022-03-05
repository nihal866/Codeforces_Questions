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

vector<int> v;
void nd(){
    int n;
    cin>>n;
    int arr[n][5] = {0};
    string tot[n];
    string s;
    fr(i, 0, n){
        cin>>s;
        tot[i] = s;
    }
    fr(i, 0, n){
        fr(j, 0, tot[i].size()){
            arr[i][tot[i][j]-'a']++;
        }
    }
    ll sum, count, mx = INT_MIN;
    fr(j, 0, 5){
        sum = 0, count = 0;
        fr(i, 0, n){
            v.push_back(arr[i][j] - (tot[i].size() - arr[i][j]));
        }
        sort(v.begin(), v.end(), greater<int>());
        fr(i, 0, v.size()){
            sum += v[i];
            if(sum<=0)  break;
            else    count++;
        }
        mx = max(mx, count);
        v.clear();
    }
    cout<<mx<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    v.reserve(500000);
    while(t--){
        nd();
    }
    return 0;
}