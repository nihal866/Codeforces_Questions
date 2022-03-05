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
    vector<int> v;
    map<int, int> mp;
    set<int> st;
    fri(i, 0, n){
        cin>>val;
        st.insert(val);
        v.push_back(val);
    }
    cout<<st.size()<<endl;
    //persons jinko koi gift nhi de rha
    stack<int> stc;
    fri(i, 1, n+1){
        if(st.find(i) == st.end())  stc.push(i);
    }
    fri(i, 0, n){
        if(mp.find(v[i]) != mp.end()){
            //Already present
            int top = stc.top();
            if(top == i+1){
                //apne aap ko gift dene ki condition
                if(stc.size() == 1){
                    int j = mp[v[i]];
                    v[i] = top;
                    swap(v[j], v[i]);
                }
                else{
                    int nxt = top;
                    stc.pop();
                    top = stc.top();
                    v[i] = top;
                    stc.push(nxt);
                }
            }
            else{
                v[i] = top;
                stc.pop();
            }
        }
        else{
            mp[v[i]] = i;
        }
    }
    fri(i, 0, n)    cout<<v[i]<<" ";
    cout<<endl;
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