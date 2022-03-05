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
        long long a, b, x, y, z;
        cin>>a>>b;
        if(b%2 == 0){
            x = (a*b) + a;
            y = (a*b) - a;
            z = x + y;
        }
        else{
            x = a * (b-1) / 2;
            y = a * (b+1) / 2;
            z = x + y;
        }
        if(x == y || y == z || z == x)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl<<x<<" "<<y<<" "<<z<<" "<<endl;
    }

    return 0;
}
