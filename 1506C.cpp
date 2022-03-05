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
        string a, b;
        int result = 0;
        cin>>a>>b;
        int dp[a.size() + 1][b.size() + 1];
        for(int i = 0; i <= a.size(); i++){
            for(int j = 0; j <= b.size(); j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 1; i <= a.size(); i++){
            for(int j = 1; j <= b.size(); j++){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    result = max(result, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        cout<<a.size() + b.size() - (2*result)<<endl;
    }

    return 0;
}
