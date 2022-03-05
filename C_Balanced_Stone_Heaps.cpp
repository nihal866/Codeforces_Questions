#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fri(i, a, b) for(ll i = a; i < b; i++)
#define frd(i, a, b) for(ll i = a; i >= b; i--)
#define g(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/g(a,b)
#define lb(v,key) lower_bound(v.begin(), v.end(), key)
#define ub(v,key) upper_bound(v.begin(), v.end(), key)
#define srtvec(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())
#define srt(arr,n) sort(arr, arr+n)
#define mem(arr,key) memset(arr, key, sizeof(arr))


int possible(vector<ll>& arr, ll mid){
    int n = arr.size();
    ll dp[n+2] = {0};
    frd(i, n-1, 2){
        if(arr[i]+dp[i] < mid)    return 0;
        ll s = 0, e = arr[i], x, ans = 0;
        while (s <= e){
            x = (s + e) >> 1;
            if(3 * x <= arr[i] && arr[i] - (3 * x) + dp[i] >= mid){
                s = x + 1;
                ans = x;
            }else{
                e = x - 1;
            }
        }
        dp[i - 1] += ans;
        dp[i - 2] += (2 * ans);
    }
    if(dp[0] + arr[0] >= mid && dp[1] + arr[1] >= mid) return 1;
    return 0;
}

void nd(){
    int n;
    cin>>n;
    vector<ll> arr(n);
    fri(i, 0, n)    cin>>arr[i];
    ll l = 1, r = 1e18, mid, ans;
    while(l <= r){
        mid = (l+r) >> 1;
        if(possible(arr, mid)){
            ans = mid;
            l = mid + 1;
        }
        else    r = mid - 1;
    }
    cout<<ans<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //preCalculatorPrime();
    cin>>t;
    while(t--){
        nd();
    }
    return 0;
}

