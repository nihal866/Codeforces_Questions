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
    ll n, o = 0, e = 0;
    cin>>n;
    ll arr[n];
    fri(i, 0, n){
        cin>>arr[i];
        if(arr[i] & 1)  o++;
        else    e++;
    }
    if(n==1){
        cout<<0<<endl;
        return;
    }
    if(o==n || e==n || abs(o-e)>1){
        cout<<-1<<endl;
        return;
    }
    //map bnao pehle wali positions ka
    //map bnao nyi positions ka
    //dono ka difference nikalo baithke
    unordered_map<ll, queue<ll>> mp1, mp2;
    ll diff1 = 0, diff2 = 0, ans, b, f;
    fri(i, 0, n){
        mp1[arr[i]].push(i+1);
    }
    ll j;
    if(o>e){
        j = 1;
        fri(i, 0, n){
            if(arr[i]%2){
                mp2[arr[i]].push(j);
                j += 2;
            }
        }
        j = 2;
        fri(i, 0, n){
            if(arr[i]%2==0){
                mp2[arr[i]].push(j);
                j += 2;
            }
        }
        fri(i, 0, n){
            b = mp1[arr[i]].front();
            mp1[arr[i]].pop();
            f = mp2[arr[i]].front();
            mp2[arr[i]].pop();
            diff1 += abs(b-f);
        }
        cout<<(diff1/2)<<endl;
        return;
    }
    else if(e>o){
        j = 1;
        fri(i, 0, n){
            if(arr[i]%2==0){
                mp2[arr[i]].push(j);
                j += 2;
            }
        }
        j = 2;
        fri(i, 0, n){
            if(arr[i]%2){
                mp2[arr[i]].push(j);
                j += 2;
            }
        }
        fri(i, 0, n){
            b = mp1[arr[i]].front();
            mp1[arr[i]].pop();
            f = mp2[arr[i]].front();
            mp2[arr[i]].pop();
            diff1 += abs(b-f);
        }
        cout<<(diff1/2)<<endl;
        return;
    }
    else{
        j = 1;
        fri(i, 0, n){
            if(arr[i]%2){
                mp2[arr[i]].push(j);
                j += 2;
            }
        }
        j = 2;
        fri(i, 0, n){
            if(arr[i]%2==0){
                mp2[arr[i]].push(j);
                j += 2;
            }
        }
        fri(i, 0, n){
            b = mp1[arr[i]].front();
            mp1[arr[i]].pop();
            f = mp2[arr[i]].front();
            mp2[arr[i]].pop();
            diff1 += abs(b-f);
        }
        mp1.clear();
        mp2.clear();
        fri(i, 0, n){
            mp1[arr[i]].push(i+1);
        }
        j = 1;
        fri(i, 0, n){
            if(arr[i]%2==0){
                mp2[arr[i]].push(j);
                j += 2;
            }
        }
        j = 2;
        fri(i, 0, n){
            if(arr[i]%2){
                mp2[arr[i]].push(j);
                j += 2;
            }
        }
        fri(i, 0, n){
            b = mp1[arr[i]].front();
            mp1[arr[i]].pop();
            f = mp2[arr[i]].front();
            mp2[arr[i]].pop();
            diff2 += abs(b-f);
        }
        cout<<(min(diff1, diff2))/2<<endl;
    }
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