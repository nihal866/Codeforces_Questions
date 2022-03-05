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


    long long n, m, nu = 1, cnt = 0;
    cin>>n>>m;
    long long arr[m];
    for(long i = 0; i < m; i++){
        cin>>arr[i];
        if(arr[i] >= nu)
            cnt += arr[i] - nu;
        else
            cnt += arr[i] - nu + n;
        nu = arr[i];
    }
    cout<<cnt;

    return 0;
}
