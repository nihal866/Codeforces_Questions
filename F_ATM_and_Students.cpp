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


const long long M = 1e9 + 7;
long long mod(long long x){
    return ((x%M + M)%M);
}


long long add(long long a, long long b){
    return mod(mod(a) + mod(b));
}


long long mul(long long a, long long b){
    return mod(mod(a) * mod(b));
}


long long max3(long long a, long long b, long long c){
    if(a > b)
        return (a > c) ? a : c;
    else
        return (b > c) ? b : c;
}


long long min3(long long a, long long b, long long c){
    if(a < b)
        return (a < c) ? a : c;
    else
        return (b < c) ? b : c;
}


void nd(){
     ll n,s;
                cin>>n>>s;
                ll a[n];
                fri(i,0,n)
                {
                    cin>>a[i];
                }
                deque<ll> dq;
                ll i=0;
                ll ss=-1,e=-1;


                ll len=0,p=0;
                for(i=0;i<n;i++)
                {
                    p=0;
                    if(a[i]+s>=0)
                    {
                        dq.push_back(a[i]);
                        s=s+a[i];
                        //cout<<s<<" ";
                        if(dq.size()>len)
                        {
                            len=dq.size();
                            e=i;
                        }

                    }
                    else
                    {
                    while(dq.empty()==false && p==0 )
                    {
                        if(a[i]+s<0)
                        {
                            s=s-dq.front();
                            //cout<<s<<" ";
                            dq.pop_front();
                        }
                        else
                        {
                            dq.push_back(a[i]);
                            s=s+a[i];
                            //cout<<s<<" ";
                            if(dq.size()>len)
                            {
                            len=dq.size();
                            e=i;
                            }
                            p=1;
                        }

                    }
                    }
                    if(dq.empty()==true && a[i]+s>=0)
                    {
                        dq.push_back(a[i]);
                        s=s+a[i];
                        //cout<<s<<" ";
                        if(dq.size()>len)
                        {
                            len=dq.size();
                            e=i;
                        }
                    }
                }
                //cout<<len<<endl;
                ss=e+1;
                ss=ss-len;
                ss++;
                e=e+1;
                if(len==0)
                {
                    cout<<-1<<endl;
                }
                else
                {
                    cout<<ss<<" "<<e<<endl;
                }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    preCalculatorPrime();
    cin>>t;
    while(t--){
        nd();
    }
    return 0;
}