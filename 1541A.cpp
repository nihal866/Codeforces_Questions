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
        int n;
        cin>>n;
        if(n%2 == 0){
            for(int i = 1; i < n; i += 2)
                cout<<i+1<<" "<<i<<" ";
        }
        else{
            for(int i = 1; i <= (n-3); i += 2)
                cout<<i+1<<" "<<i<<" ";
            cout<<n<<" "<<n-2<<" "<<n-1<<" ";
        }
        cout<<endl;
    }

    return 0;
}
