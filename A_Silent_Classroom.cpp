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
    cin>>n;
    string s;
    int arr[26] = {0}, class1[26] = {0}, class2[26] = {0};
    fri(i, 0, n){
        cin>>s;
        arr[s[0]-'a']++;
    }
    fri(i, 0, 26){
        if(arr[i] >= 2){
            class1[i] = arr[i]/2;
            class2[i] = arr[i] - class1[i];
        }
    }
    int sum = 0;
    fri(i, 0, 26){
        if(class1[i] >= 2){
            sum += (class1[i] * (class1[i] - 1))/2;
        }
        if(class2[i] >= 2){
            sum += (class2[i] * (class2[i] - 1))/2;
        }
    }
    cout<<sum<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--){
        nd();
    }
    return 0;
}