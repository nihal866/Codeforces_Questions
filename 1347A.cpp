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
        int n, cnt = 0, cl = 0, op = 0;
        cin>>n;
        string s;
        cin>>s;
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                op++;
            else
                cl++;
            if(cl > op){
                cnt++;
                cl--;
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}
