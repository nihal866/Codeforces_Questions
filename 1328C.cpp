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

long long lcm(long long a, long long b){
    long long gc = __gcd(a, b);
    return (a*b)/gc;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, i = 0;
        cin>>n;
        string s, a = "", b = "";
        cin>>s;
        for(i = 0; i < n; i++){
            if(s[i] == '1')
                break;
            if(s[i] == '2'){
                a.push_back('1');
                b.push_back('1');
            }
            else{
                a.push_back('0');
                b.push_back('0');
            }
        }
        if(i < n){
            a.push_back(s[i]);
            b.push_back('0');
        }
        for(int j = i+1; j < n; j++){
            a.push_back('0');
            b.push_back(s[j]);
        }
        cout<<a<<endl<<b<<endl;
    }

    return 0;
}
