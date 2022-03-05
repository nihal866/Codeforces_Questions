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
        int n, v;
        cin>>n;
        vector<int> odd;
        odd.reserve(2000);
        vector<int> even;
        even.reserve(2000);
        for(int i = 0; i < 2*n; i++){
            cin>>v;
            if(v%2==0)
                even.push_back(v);
            else
                odd.push_back(v);
        }
        if(even.size() == odd.size())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }

    return 0;
}
