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

    int a, b, cnt = 0;
    cin>>a>>b;
    while(a <= b){
        a*= 3;
        b *= 2;
        cnt++;
    }
    cout<<cnt;

    return 0;
}
