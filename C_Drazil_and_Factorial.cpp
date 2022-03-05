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
    string s,M[]={"","","2","3","322","5","53","7","7222","7332"};
    ll a;
    cin>>a>>a;
	while(a)s+=M[a%10],a/=10;
	sort(s.rbegin(),s.rend());
	cout<<s;
}

void nd1(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int o = 0, z = 0;
    fri(i, 0, n){
        if(s[i] == '0') z++;
        else if(s[i] == '1')    o++;
        else    continue;
    }
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(10);
    int arr[10] = {0}, num;
    fri(i, 0, n){
        num = s[i] - '0';
        if(num > 1){
            auto itr = lb(v, num);
            if(*itr == num) arr[num]++;
            else{
                itr--;
                arr[*itr]++;
                int m = *itr, prod = 1;
                frd(i, num, m+1)    prod *= i;
                while(num%2 == 0){
                    arr[2]++;
                    num/=2;
                }
                while(num%3 == 0){
                    arr[3]++;
                    num/=3;
                }
            }
        }   
    }
    fri(i, 0, arr[7])   cout<<'7';
    fri(i, 0, arr[5])   cout<<'5';
    fri(i, 0, arr[3])   cout<<'3';
    fri(i, 0, arr[2])   cout<<'2';
    cout<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
 //   cin>>t;
    while(t--){
        nd();
    }
    return 0;
}