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

class SGTree{
    private:
        vector<int> seg;
    public:
        SGTree(int n){
            seg.resize(4*n + 1);
        }

        int test(){
            return seg[0];
        }

        void build(int idx, int low, int high, vector<int> arr, bool flag){
            // last segment
            if(low == high){
                seg[idx] = arr[low];
                return;
            }
            //cout<<"hello"<<endl;
            int mid = (low + high) >> 1;
            build(2*idx + 1, low, mid, arr, !flag);
            build(2*idx + 2, mid + 1, high, arr, !flag);
            //seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
            if(flag)    seg[idx] = (seg[2*idx + 1] | seg[2*idx + 2]);
            else    seg[idx] = (seg[2*idx + 1] ^ seg[2*idx + 2]);
        }

        void update(int idx, int low, int high, int ind, int val, bool flag){
            if(low == high){
                seg[idx] = val;
                return;
            }
            //cout<<"hello"<<endl;
            int mid = (low + high) >> 1;
            if(ind <= mid)  update(2*idx + 1, low, mid, ind, val, !flag);
            else    update(2*idx + 2, mid+1, high, ind, val, !flag);
            if(flag)    seg[idx] = (seg[2*idx + 1] | seg[2*idx + 2]);
            else    seg[idx] = (seg[2*idx + 1] ^ seg[2*idx + 2]);
        }
};

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
    
void nd(){
    int m, q;
    cin>>m>>q;
    int n = pow(2, m);
    vector<int> arr(n);
    fri(i, 0, n)    cin>>arr[i];
    SGTree seg(n);
    bool flag = (m & 1) ? true : false;
    seg.build(0, 0, n-1, arr, flag);
    while(q--){
        int ind, val;
        cin>>ind>>val;
        seg.update(0, 0, n-1, ind-1, val, flag);
        // arr[ind-1] = val;
        cout<<seg.test()<<endl;
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