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

    int n;
    cin>>n;
    long long d = 0, e = 0;
    long long a[n];
    long long b[n-1];
    long long c[n-1];
    for(int i = 0; i < n; i++){
        cin>>a[i];
        d = d ^ a[i];
    }
    for(int i = 0; i < n-1; i++){
        cin>>b[i];
        d = d ^ b[i];
        e = e ^ b[i];
    }
    cout<<d<<endl;
    for(int i = 0; i < n-2; i++){
        cin>>c[i];
        e = e ^ c[i];
    }
    cout<<e<<endl;

    return 0;
}
