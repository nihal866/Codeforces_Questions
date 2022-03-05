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

    int n, a, b, cnt = 0;
    cin>>n>>a>>b;
    for(int i = n; i > a; i--){
        if(n-i > b)
            break;
        cnt++;
    }
    cout<<cnt;

    return 0;
}
