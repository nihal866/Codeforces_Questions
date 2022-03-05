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

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        long long n, a, b;
        cin>>n>>a>>b;
        bool pre = false;
        for(long long i = 1; i <= n; i *= a){
            if((n-i)%b == 0){
                pre = true;
                break;
            }
            if(a==1){
                break;
            }
        }
        if(pre)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}
