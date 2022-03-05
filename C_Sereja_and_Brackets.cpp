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

struct info{
    int open;
    int close;
    int full;

    info(){
        open = 0;
        close = 0;
        full = 0;
    }

    info(int o, int c, int f){
        open = o;
        close = c;
        full = f;
    }
};

class SGTree{
    private:
        vector<info> seg;
    public:
        SGTree(int n){
            seg.resize(4*n + 1);
        }

        info test(){
            return seg[0];
        }
        
        info merge(info left, info right){
            info ans = info();
            ans.full = left.full + right.full + min(left.open, right.close);
            ans.open = left.open + right.open - min(left.open, right.close);
            ans.close = left.close + right.close - min(left.open, right.close);
            return ans;
        }

        void build(int idx, int low, int high, string s){
            // last segment
            if(low == high){
                seg[idx].full = 0;
                seg[idx].open = s[low]=='(';
                seg[idx].close = s[low]==')';
                return;
            }
            int mid = (low + high) >> 1;
            
            build(2*idx + 1, low, mid, s);
            build(2*idx + 2, mid + 1, high, s);
            
            seg[idx] = merge(seg[2*idx+1], seg[2*idx+2]);
        }

        info query(int idx, int low, int high, int l, int r){
            //  no overlapping
            if(high<l || low>r) return info();
            //  complete overlapping
            if(l<=low && high<=r)   return seg[idx];
            //  partial overlapping
            int mid = (low + high) >> 1;
            info left = query(2*idx + 1, low, mid, l, r);
            info right = query(2*idx + 2,mid+1, high, l, r);
            return merge(left, right);
        }
};

void nd(){
    string s;
    cin>>s;
    int n = s.size();
    SGTree seg(n);
    seg.build(0, 0, n-1, s);
    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<2*seg.query(0, 0, n-1, l-1, r-1).full<<endl;
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