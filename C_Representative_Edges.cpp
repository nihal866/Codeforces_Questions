#include<bits/stdc++.h>
using namespace std;
#define int long double
#define fri(i, a, b) for(int i = a; i < b; i++)
#define frd(i, a, b) for(int i = a; i >= b; i--)
#define g(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/g(a,b)
#define lb(v,key) lower_bound(v.begin(), v.end(), key)
#define ub(v,key) upper_bound(v.begin(), v.end(), key)
#define srtvec(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())
#define srt(arr,n) sort(arr, arr+n)
#define mem(arr,key) memset(arr, key, sizeof(arr))

void nd(){
    int n, diff, count;
    cin>>n;
    vector<int> arr(n);
    fri(i, 0, n)    cin>>arr[i];
    if(n==1 || n==2){
        cout<<0<<endl;
        return;
    }
    int res = n;
    fri(i, 0, n-1){
        fri(j, i+1, n){
            diff = (arr[j] - arr[i])/(j-i);
            count = 0;
            fri(k, 0, n){
                if(k!=i && ((diff*(i-k)+arr[k]) != arr[i]))   count++;
            }
            res = min(res, count);
        }
    }
    cout<<res<<endl;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
 //   preCalculatorPrime();
    cin>>t;
    while(t--){
        nd();
    }
    return 0;
}