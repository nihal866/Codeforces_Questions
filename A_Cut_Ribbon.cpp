#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, a, b, c;
    cin>>n>>a>>b>>c;
    int mn = min(a, min(b, c));
    int mx = max(a, max(b, c));
    int md = a^b^c^mn^mx;

    int pieces = 0;
    if(n%mn == 0)
        pieces += n/mn;
    else{
        pieces += n/mn;
        if((n%mn)%md == 0){
            pieces += (n%mn)/md;
        }
        else{
            int d = n%mn;
            int lcm = (md*mn) / __gcd(md, mn);
            int lcm1 = (lcm*mn) / __gcd(lcm, mn);
            pieces -= lcm1/mn;
            pieces += lcm/lcm;
        }
    }
    cout<<pieces;

    return 0;
}