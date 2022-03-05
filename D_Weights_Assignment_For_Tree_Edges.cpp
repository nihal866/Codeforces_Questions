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

const ll maxi = 200005 - 1;

ll arr[maxi], indOf[maxi], dep[maxi], ans[maxi];
vector<ll> nei[maxi];

void nd()
{
    ll n;
    cin >> n;
    fri(v, 1, n+1)
    {
        nei[v].clear();
    }
    ll root = -1;
    for (ll v = 1; v <= n; ++v)
    {
        cin >> arr[v];
        if (arr[v] == v)
        {
            root = v;
        }
        else
        {
            nei[arr[v]].push_back(v);
        }
    }
    for (ll i = 1; i <= n; ++i)
    {
        ll v;
        cin >> v;
        indOf[v] = i;
    }
    ll cur = 1;
    priority_queue<pair<ll, ll>> q;
    q.push({-indOf[root], root});
    ll maxDep = 1;
    bool ok = true;
    while (q.size())
    {
        ll i = q.top().first;
        ll v = q.top().second;
        q.pop();
        i *= -1;
        if (i != cur)
        {
            ok = false;
            break;
        }
        else
        {
            ll curDep = arr[v] != v ? dep[arr[v]] : 0;
            ans[v] = maxDep + 1 - curDep;
            if (v == root)
            {
                ans[v] = 0;
            }
            dep[v] = curDep + ans[v];
            maxDep = dep[v];
            ++cur;
            for (ll to : nei[v])
            {
                q.push({-indOf[to], to});
            }
        }
    }
    if (ok)
    {
        for (ll i = 1; i <= n; ++i)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    else
    {
        cout << "-1\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    preCalculatorPrime();
    cin >> t;
    while (t--)
    {
        nd();
    }
    return 0;
}