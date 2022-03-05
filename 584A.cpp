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

    int n, t;
    cin>>n>>t;
    if(t < 10){
        for(int i = 0; i < n; i++)
            cout<<t;
    }
    else{
        if(n == 1)
            cout<<-1;
        else{
            cout<<1;
            for(int i = 1; i < n; i++)
                cout<<0;
        }
    }

    return 0;
}
