#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>

#define ll long long
#define fri(n) for(int i = 0; i < n; i++)
#define frj(n) for(int j = 0; i < n; j++)
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
        ll a, b;
        cin>>a>>b;
        ll mn = min(a, b), mx = max(a, b), price = 0;
        if(mn%3 == 0)
            price += mn/3 + mn/3;
        else if(mn%3 == 1){
            price += mn/3 + mn/3;
            if(mx != mn)
                price++;
        }
        else if(mn%3 == 2){
            price += mn/3 + mn/3;
            price++;
            if(mx-mn > 1)
                price++;
        }

        cout<<price<<endl;
    }

    return 0;
}
