#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        ll sum = 0;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            sum += arr[i];
        }
        ll mod = sum%n;
        if(mod == 0)
            cout<<0<<endl;
        else{
            ll l = n - mod;
            cout<<mod*l<<endl;
        }
    }

    return 0;
}
