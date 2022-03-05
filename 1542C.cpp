#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
using namespace std;

long long lcm(long long a, long long b){
    long long gc = __gcd(a, b);
    return (a*b)/gc;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        long long n, m, ans;
        cin>>n;
        long long i = 2, l1 = 1, l2;
        ans = ((n+1)/2) * 2;
        m = n/2;
        while(m > 0){
            l1 = lcm(l1, i);
            l2 = lcm(l1, i+1);
            long long val = (n/l1) - (n/l2);
            m -= val;
            ans += (++i) * val;
            ans = ans % 1000000007;
        }
        cout<<ans<<endl;
    }

    return 0;
}
