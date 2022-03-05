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

bool square(long n){
    long i = 1;
    while(i*i <= n){
        if(i*i == n)
            return true;
        i++;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        long n;
        cin>>n;
        if(n%2 == 0){
            if(square(n/2))
                cout<<"YES"<<endl;
            else if(n%4 == 0 && square(n/4))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
