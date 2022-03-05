#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ll a, b, gc, no;
        cin>>a>>b;
        if(a == b)
            gc = no = 0;
        else{
            gc = abs(a-b);
            if(__gcd(a, b) == gc)
                no = 0;
            else{
                ll l = a%gc;
                no = min(l, gc - l);
            }
        }
        cout<<gc<<" "<<no<<endl;
    }

    return 0;
}
