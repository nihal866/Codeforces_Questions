#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define fri(i, a, b) for(int i = a; i < b; i++)
#define frd(i, a, b) for(int i = a; i >= b; i--)
#define g(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/g(a,b)
#define vll vector<int>
#define lb(v,key) lower_bound(v.begin(), v.end(), key)
#define ub(v,key) upper_bound(v.begin(), v.end(), key)
#define srtvec(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define srt(arr,n) sort(arr, arr+n)
#define mem(arr,key) memset(arr, key, sizeof(arr))


const int N = 1000000;
bool isPrime[N];
set<int> s;
void preCalculatorPrime(){
    fill(isPrime+2, isPrime+N, true);
    for(int i = 2; i*i < N; i++){
        for(int j = i*i; j < N; j=j+i)	isPrime[j] = false; }
    for(int i = 2; i < N; i++){
        if(isPrime[i])	s.insert(i); }}
const long long M = 1e9 + 7;
long long mod(long long x){	return ((x%M + M)%M); }
long long add(long long a, long long b){	return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b){	return mod(mod(a) * mod(b)); }
long long max3(long long a, long long b, long long c){
    if(a > b)	return (a > c) ? a : c;
    else	return (b > c) ? b : c; }
long long min3(long long a, long long b, long long c){
    if(a < b)	return (a < c) ? a : c;
    else	return (b < c) ? b : c; }
    
void clearSet(set<int>& st, int pos){
    st.erase(pos);
    st.erase(pos+1);
    st.erase(pos+2);
}

void addSet(set<int>& st, int pos){
    st.insert(pos);
    st.insert(pos+1);
    st.insert(pos+2);
}

void checkA(string& s, set<int>& st, char c, int pos){
    if(c == s[pos]) return;
    char ch = s[pos];
    if(ch == 'a'){
        if(st.find(pos) != st.end())    clearSet(st, pos);
    }
    else if(ch == 'b'){
        if(st.find(pos) != st.end())    clearSet(st, pos-1);
    }
    else{
        if(st.find(pos) != st.end())    clearSet(st, pos-2);
    }
    s[pos] = c;
    if(pos >= s.size()-2)   return;
    if(s[pos]=='a' && s[pos+1]=='b' && s[pos+2]=='c')   addSet(st, pos);
}

void checkB(string& s, set<int>& st, char c, int pos){
    if(c == s[pos]) return;
    char ch = s[pos];
    if(ch == 'a'){
        if(st.find(pos) != st.end())    clearSet(st, pos);
    }
    else if(ch == 'b'){
        if(st.find(pos) != st.end())    clearSet(st, pos-1);
    }
    else{
        if(st.find(pos) != st.end())    clearSet(st, pos-2);
    }
    s[pos] = c;
    if(pos > s.size()-2 && pos < 1) return;
    if(s[pos-1]=='a' && s[pos]=='b' && s[pos+1]=='c')   addSet(st, pos-1);
}

void checkC(string& s, set<int>& st, char c, int pos){
    if(c == s[pos]) return;
    char ch = s[pos];
    if(ch == 'a'){
        if(st.find(pos) != st.end())    clearSet(st, pos);
    }
    else if(ch == 'b'){
        if(st.find(pos) != st.end())    clearSet(st, pos-1);
    }
    else{
        if(st.find(pos) != st.end())    clearSet(st, pos-2);
    }
    s[pos] = c;
    if(pos < 2) return;
    if(s[pos-2]=='a' && s[pos-1]=='b' && s[pos]=='c')   addSet(st, pos-2);
}

void nd(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int count = 0;
    set<int> st;
    fri(i, 0, n-2){
        if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='c'){
            st.insert(i);
            st.insert(i+1);
            st.insert(i+2);
        }
    }
    while(q--){
        int pos;
        char c;
        cin>>pos>>c;
        if(c == 'a')    checkA(s, st, c, pos-1);
        else if(c == 'b')   checkB(s, st, c, pos-1);
        else    checkC(s, st, c, pos-1);
        cout<<st.size()/3<<endl;
    }
}
    
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--){
        nd();
    }
    return 0;
}