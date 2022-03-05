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
        long long x, y, a, b, price1 = 0, price2 = 0, price3 = 0;
        cin>>x>>y;
        cin>>a>>b;

        price1 += min(x, y) * b + (max(x, y) - min(x, y)) * a;

        price2 += (x+y) * a;

        price3 += max(x, y) * b + (max(x, y) - min(x, y)) * a;

        cout<<min(price1, min(price2, price3))<<endl;
    }

    return 0;
}
