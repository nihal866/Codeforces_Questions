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
    int n;
    vector<int> arr[10];
    string s;
    cin>>n;
    cin>>s;
    for(int i = 0; i < n; i++){
        arr[s[i]-'0'].push_back(i);
    }
    if(arr[2].size()+arr[3].size()+arr[5].size()+arr[7].size() < n){
        cout<<1<<endl;
        for(int i = 0; i < n; i++){
            if(s[i]!='2' && s[i]!='3' && s[i]!='5' && s[i]!='7'){
                cout<<s[i]<<endl;
                return;
            }
        }
    }
    if(arr[2].size() && s[0]!='2'){
        cout<<2<<endl<<s[0]<<'2'<<endl;
        return;
    }
    if(arr[5].size() && s[0]!='5'){
        cout<<2<<endl<<s[0]<<'5'<<endl;
        return;
    }
    if(arr[2].size()>1){
        cout<<2<<endl<<22<<endl;
        return;
    }
    if(arr[3].size()>1){
        cout<<2<<endl<<33<<endl;
        return;
    }
    if(arr[5].size()>1){
        cout<<2<<endl<<55<<endl;
        return;
    }
    if(arr[7].size()>1){
        cout<<2<<endl<<77<<endl;
        return;
    }
    if(s[0] == '2') cout<<2<<endl<<27<<endl;
    else    cout<<2<<endl<<57<<endl;
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