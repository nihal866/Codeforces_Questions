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
        if(n == 1)
            cout<<-1;
        else{
            cout<<5;
            for(int i = 1; i < n; i++)
                cout<<3;
        }
        cout<<endl;
    }

    return 0;
}
