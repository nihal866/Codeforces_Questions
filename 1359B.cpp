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
        int n, m, x, y, white = 0, dWhite = 0;
        cin>>n>>m>>x>>y;
        char arr[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>arr[i][j];
                if(arr[i][j] == '.')
                    white++;
            }
        }
        if(2*x <= y)
            cout<<x*white<<endl;
        else{
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m-1; j++){
                    if((arr[i][j] == arr[i][j+1]) && arr[i][j] == '.'){
                        dWhite++;
                        j++;
                    }
                }
            }
            cout<<(dWhite*y + (white - 2*dWhite)*x)<<endl;
        }
    }

    return 0;
}
