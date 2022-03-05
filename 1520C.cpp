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
        long n, cnt = 1;
        cin>>n;
        long arr[n][n];
        if(n > 2){
            for(long i = 0; i < n; i++)
                arr[i][i] = cnt++;
            for(int i = 1; i < n; i++){
                for(long j = i; j < n; j++)
                    arr[j][j-i] = cnt++;
                for(long j = i; j < n; j++)
                    arr[j-i][j] = cnt++;
            }
            for(long i = 0; i < n; i++){
                for(long j = 0; j < n; j++)
                    cout<<arr[i][j]<<" ";
                cout<<endl;
            }
        }
        else{
            if(n == 1)
                cout<<1<<endl;
            else
                cout<<-1<<endl;
        }
    }

    return 0;
}
