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

    long long n, k, no;
    cin>>n>>k;
    if(n%2 == 0){
        if(k <= n/2)
            no = (2 * k) - 1;
        else
            no = 2 * (k - (n/2));
    }
    else{
        if(k > (n+1)/2)
            no = (k - (n+1)/2) * 2;
        else
            no = (2*k) - 1;
    }
    cout<<no<<endl;

    return 0;
}
