#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ll n, k, m = 0, i;
        cin>>n>>k;
        while(1){
            i = k/n;
            if(i == m)
                break;
            k += (i-m);
            m = i;
        }
        cout<<k<<endl;
    }

    return 0;
}
