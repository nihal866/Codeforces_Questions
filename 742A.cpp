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

    long n;
    cin>>n;
    int ans;
    if(n == 0)
        ans = 1;
    else{
        n = n%4;
        if(n == 0)
            ans = 6;
        else if(n == 1)
            ans = 8;
        else if(n == 2)
            ans = 4;
        else if(n == 3)
            ans = 2;
    }
    cout<<ans;

    return 0;
}
