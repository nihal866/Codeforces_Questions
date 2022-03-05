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

    long long n, x, cnt = 0;
    cin>>n>>x;
    if(n >= x){
        for(long long i = 1; i <= x; i++){
            if(x%i == 0)
                cnt++;
        }
    }
    else{
        for(long long i = 1; i <= n; i++){
            if(x%i == 0)
                if(x/i <= n)
                    cnt++;
        }
    }
    cout<<cnt;

    return 0;
}
