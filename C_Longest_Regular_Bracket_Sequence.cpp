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

void nd(){
    string s;
    cin>>s;
    stack<int> st;
    map<int, int> mp;
    int ans = 0;
    int n = s.size();
    vector<int> end(n, -1), ext(n, -1);
    for(int i = 0; i < n; i++){
        //cout<<"h"<<endl;
        if(s[i] == ')'){
            if(st.empty())   continue;
            int idx = st.top();
            end[i] = idx;
            ext[i] = idx;
            st.pop();
            if(idx){
                if(s[idx-1] == ')' && end[idx-1] != -1)   ext[i] = ext[idx-1];
            }
            mp[i-ext[i]+1]++;
            ans = max(ans, i-ext[i]+1);
        }
        else    st.push(i);
    }
    if(ans == 0)    cout<<"0 1"<<endl;
    else    cout<<ans<<" "<<mp[ans]<<endl;
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