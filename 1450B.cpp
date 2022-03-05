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
        int n, k;
        cin>>n>>k;
        bool possible = false;
        vector< pair<int,int> > v;
        v.reserve(n);
        for(int  i = 0; i < n; i++)
            cin>>v[i].first>>v[i].second;
        for(int i = 0; i < n; i++){
            int total = 0;
            for(int j = 0; j < n; j++){
                if(abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second) <= k)
                    total++;
            }
            if(total == n){
                cout<<1<<endl;
                possible = true;
                break;
            }
        }
        if(!possible)
            cout<<-1<<endl;
    }

    return 0;
}
