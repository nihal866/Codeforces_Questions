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


void nd(){
    int n;
    cin>>n;
    int arr[n];
    map<int, vector<int>> mp1, mp2;
    fr(i, 0, n) cin>>arr[i],    mp1[arr[i]].push_back(i);
    sort(arr, arr+n);
    fr(i, 0, n) mp2[arr[i]].push_back(i);
    map<int, vector<int>>::iterator itr;
    int oa, ea, ob, eb;
    for(auto &a:mp1){
        oa = 0, ea = 0, ob = 0, eb = 0;
        itr = mp2.find(a.first);
        fr(i, 0, a.second.size()){
            if(a.second[i]%2)   oa++;
            else    ea++;
        }
        fr(i, 0, itr->second.size()){
            if(itr->second[i]%2)    ob++;
            else    eb++;
        }
        if(oa!=ob || ea!=eb){
            cout<<"NO"<<endl;
            return;
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