// pro hai hum
// shubham_kr
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
//Naive Solution as follows...
#include<bits//stdc++.h>
using namespace std;
#define  fri(x,n)                 for(int64_t i=x;i<n;i++)
#define  frj(x,n)                 for(int64_t j=x;j<n;j++)
#define  mem(a,x)                  memset(a,x,sizeof(a))
#define  nline                     "\n"
typedef long long int ll;
//..............................................***............................................//
                                              //code
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mmiprime(ll a, ll b) {return expo(a, b - 2, b);}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mmiprime(b, m), m) + m) % m;}  //only for prime m
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
//................................................*..............................................//

typedef long int  l;
#define pb(i)                push_back(i)
#define ppb()                pop_back()
#define pf(i)                push_front(i)
#define ppf()                pop_front()
#define gcd(a,b)             __gcd(a,b)
#define findv(vec,i)        (std::find(vec.begin(),vec.end(),i)!= (vec.end()))
#define swap(a,b)        a=a+b; \
                           b=a-b; \
                             a=a-b
#define all(x)            (x).begin(),(x).end()
#define debug(x) {cerr<<x<<endl;}
#define debug1(x) {cerr<<x<<" ";}
#define ff first
#define ss second
bool sortbysec(const pair<int,int>&a, const pair<int,int>&b)
{
    return(a.second<b.second);
}

//................................................................*............................//

#define mod 1000000007
const long long INF=1e18;
//...................................................................................................

void sk_kr()
{
   
 int n,m;
 cin>>n>>m;
 int a[n+1];
 mem(a,0);
 for(int i=0;i<m;i++)
 {
    int x,y;
    cin>>x>>y;
    if(x>y)
    {
        a[y]++;
    }
    else
    a[x]++;
 }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
      if(a[i]==0)
        ans++;
    }
    int q;
    cin>>q;
   map<int,int>mp;
    while(q--)
    {
        int x;
        cin>>x;
        if(x==3)
        {
            cout<<ans<<endl;
        }
        else 
        {
            int u,v;
            cin>>u>>v;
            u=min(u,v);
            if(x==1)
            {
                 a[u]++;
                if(a[u]==1)
                {
                    ans--;
                }
            }
            else
            {
                a[u]--;
                if(a[u]==0)
                {
                   ans++;
                }
            }
        }
    }
    return;
}
int main()
{    
     ios_base::sync_with_stdio(0), cin.tie(0);
     auto begin=chrono::high_resolution_clock::now();
      #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
        #endif
    int t;
    t=1;
    //cin>>t;
    while(t--)
     {   
         sk_kr();
     } 
    auto end=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(end-begin);
    #ifndef ONLINE_JUDGE
   cerr << "TIME:-"<< duration.count()<<"\n";
   #endif
    return 0;
}