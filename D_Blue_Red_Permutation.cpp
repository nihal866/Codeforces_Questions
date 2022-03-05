#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fri(i, a, b) for (ll i = a; i < b; i++)
#define frd(i, a, b) for (ll i = a; i >= b; i--)
#define g(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / g(a, b)
#define lb(v, key) lower_bound(v.begin(), v.end(), key)
#define ub(v, key) upper_bound(v.begin(), v.end(), key)
#define srtvec(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())
#define srt(arr, n) sort(arr, arr + n)
#define mem(arr, key) memset(arr, key, sizeof(arr))
#define vi vector<int>

const int N = 1000000;
bool isPrime[N];
set<int> s;

void preCalculatorPrime()
{
    fill(isPrime + 2, isPrime + N, true);
    for (int i = 2; i * i < N; i++)
    {
        for (int j = i * i; j < N; j = j + i)
            isPrime[j] = false;
    }
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
            s.insert(i);
    }
}

const long long M = 1e9 + 7;
long long mod(long long x)
{
    return ((x % M + M) % M);
}

long long add(long long a, long long b)
{
    return mod(mod(a) + mod(b));
}

long long mul(long long a, long long b)
{
    return mod(mod(a) * mod(b));
}

long long max3(long long a, long long b, long long c)
{
    if (a > b)
        return (a > c) ? a : c;
    else
        return (b > c) ? b : c;
}

long long min3(long long a, long long b, long long c)
{
    if (a < b)
        return (a < c) ? a : c;
    else
        return (b < c) ? b : c;
}

bool nd()
{
    int n;
    cin >> n;
    vector<ll> a(n+1);
    fri(i, 0, n) { cin >> a[i]; }

    string s;
    cin >> s;
    vector<ll> ss(n + 10, 0), sss(n + 10, 0);
    fri(i, 0, n)
    {
        if (s[i] == 'B')
        {
            if (a[i] < 1)
                return 0;
            if (a[i] > n)
                a[i] = n;
            ss[a[i]]++;
        }
        else
        {
            if (a[i] > n)
                return 0;
            if (a[i] < 1)
                a[i] = 1;
            sss[a[i]]++;
        }
    }
    fri(i, 1, n + 1) sss[i] += sss[i - 1];
    for (int i = n - 1; i >= 0; i--)
        ss[i] += ss[i + 1];

    ll b = 0;
    
    fri(i, 1, 1 + n)
    {
        
        sss[i] -= b;
        if (ss[i] > 0)
        {
            ss[i]--;
        }
        else if (sss[i] > 0)
        {
            b++;
        }
        else
            return 0;
        ss[i + 1] = min(ss[i + 1], ss[i]);
        
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        if (nd())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}