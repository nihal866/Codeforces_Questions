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

    int n, cnt = 0, i = 0;
    cin>>n;
    while(n-i > 0){
        cnt += n-i;
        cnt += i*(n-i-1);
        i++;
    }
    cout<<cnt;

    return 0;
}
