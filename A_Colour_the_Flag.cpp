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
    int n, m;
    cin>>n>>m;
    char flag[n][m];
    fri(i, 0, n){
        fri(j, 0, m)    cin>>flag[i][j];
    }
    bool poss1o = true, poss1e = false, poss2o = false, poss2e = true ,pr = false, pw = true;
    fri(i, 0, n){
        fri(j, 0, m){
            if((i+j)%2){
                if(flag[i][j] == 'R')   pr=true,    poss2o=true;
                if(flag[i][j] == 'W'){
                    poss1o = false;
                    break;
                }
            }
            else{
                if(flag[i][j] == 'W')   pw=true;
                if(flag[i][j] == 'R'){
                    poss2e = false;
                    break;
                }
            }
        }
    }
    if(poss1^poss2){
        if(pr&pw){
            cout<<"NO"<<endl;
            return;
        }
        if(!poss1 && !pr)  poss1=false;
        else if(!poss2)  poss1=false;
    }
    cout<<"YES"<<endl;
    if(poss1){
        fri(i, 0, n){
            fri(j, 0, m){
                if((i+j)%2) flag[i][j]='R';
                else    flag[i][j]='W';
            }
        }
    }
    else{
        fri(i, 0, n){
            fri(j, 0, m){
                if((i+j)%2) flag[i][j]='W';
                else    flag[i][j]='R';
            }
        }
    }
    fri(i, 0, n){
        fri(j, 0, m)    cout<<flag[i][j];
        cout<<endl;
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