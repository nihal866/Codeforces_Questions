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
        int n, m, k, ans;
        cin>>n>>m>>k;
        int a = n/k;
        int sum = (((2*a) + 1 - k) * k) / 2;
        if(m>sum || m==0)
            ans = 0;
        else{
            if(m >= 2*a - 1)
                ans = 1;
            else if(m > a)
                ans = a + a - m;
            else
                ans = m;
        }
        cout<<ans<<endl;
    }

    return 0;
}
