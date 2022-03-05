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

bool isPrime(int n){
    int m = sqrt(n);
    for(int i = 2; i <= m; i++){
        if(n%i == 0)
            return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, k;
    cin>>n>>k;
    string s, res = "";
    cin>>s;
    if(k <= n){
        for(int i = 0; i < k; i++)
            res += s[i];
    }
    else{
        while(k%n != 0)
            n--;
        string r = "";
        for(int i = 0; i < n; i++)
            r += s[i];
        for(int i = 0; i < (k/n); i++)
            res += r;
    }
    cout<<res;

    return 0;
}
