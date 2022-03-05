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
        long long n, m = 1, k;
        cin>>n>>k;
        if(n > k)
            k = ((n/k) + 1) * k;
        if(k%n == 0)
            cout<<k/n<<endl;
        else
            cout<<(k/n)+1<<endl;
    }

    return 0;
}
