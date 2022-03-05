#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m, a, b;
    cin>>n>>m>>a>>b;
    if(a*m <= b)
        cout<<n*a<<endl;
    else
        cout<<(n/m)*b + min(a*(n%m), b)<<endl;

    return 0;
}

