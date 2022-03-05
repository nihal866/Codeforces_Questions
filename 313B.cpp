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

    string s;
    cin>>s;
    int n, m;
    n = s.size();
    cin>>m;
    while(m--){
        int l, r;
        cin>>l>>r;
        l--;
        r--;
        int cnt = 0;
        for(int i = l; i < r; i++){
            if(s[i] == s[i+1])
                cnt++;
        }
        cout<<cnt<<endl;
    }

    return 0;
}
