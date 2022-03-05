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

    long long n;
    cin>>n;
    int cnt = 0;
    if(n%2 != 0){
        cnt++;
        n--;
    }
    while(n%2 == 0 && n>=1){
        n /= 2;
        if(n%2 != 0){
            cnt++;
            n--;
        }
    }
    cout<<cnt;

    return 0;
}
