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
    string s;
    cin>>s;
    int arr[26] = {0};
    set<string> st;
    fr(i, 0, n){
        arr[s[i]-'a']++;
    }
    fr(i, 0, 26){
        if(arr[i] == 0){
            cout<<(char)('a' + i)<<endl;
            return;
        }
    }
    fr(i, 0, n-1){
        string a = "";
        a += s[i];
        a += s[i+1];
        st.insert(a);
    }
    fr(i, 0, 26){
        fr(j, 0, 26){
            string b = "";
            b += (char)('a' + i);
            b += (char)('a' + j);
            if(st.find(b) == st.end()){
                cout<<b<<endl;
                return;
            }
        }
    }
    st.clear();
    fr(i, 0, n-2){
        string a = "";
        a += s[i];
        a += s[i+1];
        a += s[i+2];
        st.insert(a);
    }
    fr(i, 0, 26){
        fr(j, 0, 26){
            fr(k, 0, 26){
                string b = "";
                b += (char)('a' + i);
                b += (char)('a' + j);
                b += (char)('a' + k);
                if(st.find(b) == st.end()){
                    cout<<b<<endl;
                    return;
                }
            }
        }
    }
    st.clear();
    return;
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
