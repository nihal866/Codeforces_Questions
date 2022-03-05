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
    string s, del = "";
    cin>>s;
    int n = s.size();
    int arr[26] = {0};
    int visited[26] = {0};
    frd(i, n-1, 0){
        arr[s[i] - 'a']++;
        if(visited[s[i]-'a'] == 0)  del+=s[i],  visited[s[i]-'a']++;
    }
    string del1 = "";
    frd(i, del.size()-1, 0) del1 += del[i];
    int len = 0, i = 1;
    fri(i, 0, del.size()){
        char c = del1[i];
        if(arr[c-'a'] % (i+1) != 0){
            cout<<-1<<endl;
            return;
        }
        len += arr[c-'a']/(i+1);
    }
    string t = "";
    fri(i, 0, len)  t+=s[i];
    string nt = t, f = t, m;
    fri(i, 0, del.size()){
        int j = 0;
        m = "";
        while(j < nt.size()){
            if(nt[j] != del1[i]){
                f += nt[j];
                m += nt[j];
            }
            j++;
        }
        nt = m;
    }
    if(f == s){
        cout<<t<<" "<<del1<<endl;
    }
    else    cout<<-1<<endl;
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