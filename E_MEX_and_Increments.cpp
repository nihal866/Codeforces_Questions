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

bool check(ll i){
    if(i > 40)  return true;
    if(i < 30)  return false;
    return true;
}

void nd()
{
    ll n, primes;
    cin >> n;
    vector<ll> arr(n), ff;
    map<ll, ll> mp;
    fri(i, 0, n){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    srtvec(arr);

    ll ans = 0;
    ll last = -1;
    ll poss = 0;
    ll bal;

    for (ll i = 0; i <= n; i++)
    {   
        bool nautanki = check(i);
        if ((i-1)>last || poss==1)
        {
            poss = 1;
            cout << -1 << ' ';
        }
        else
            cout << ans + mp[i] << ' ';

        if (mp[i])
        {
            last = i;
            if (mp[i] > 1)
            {
                ff.push_back(i);
                mp[i]--;
            }
        }
        else if (ff.size())
        {
            last = i;
            bal = ff[ff.size()-1];
            ans += i - bal;
            mp[bal]--;
            if (mp[bal] == 0)
                ff.pop_back();
        }
    }

    cout << endl;
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