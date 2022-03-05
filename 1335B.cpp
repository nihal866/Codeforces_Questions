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

    int t;
    cin>>t;
    while(t--){
        int n, a, b, i = 0;
        cin>>n>>a>>b;
        string s = "abcdefghijklmnopqrstuvwxyz";
        while(i < n){
            cout<<s[i%b];
            i++;
        }
        cout<<endl;
    }

    return 0;
}
