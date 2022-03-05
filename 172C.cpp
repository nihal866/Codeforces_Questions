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

vector<int> who[10001];
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector< pair<int, int> > v;
    v.reserve(200000);
    vector<int> pass;
    pass.reserve(200000);
    for(int i = 1; i <= n; i++)
        cin>>v[i].first>>v[i].second;
    int t = 0;
    int arr[n+1];
    for(int i = 1; i <= n; i+=m){
        if(i+m-1 <= n)
            t = max(t, v[i+m-1].first);
        else
            t = max(t, v[n].first);

        map<int, int> mp;
        for(int j = i; j < min(i+m, n+1); j++){
            mp[v[j].second]++;
            who[v[j].second].push_back(j);
        }
        int last;
        for(pair<int,int> child:mp){
            for(int child1:who[child.first])
                arr[child1] = t + child.first;
            who[child.first].clear();
            t += (1 + child.second/2);
            last = child.first;
        }
        t += 2*last;
    }
    for(int i = 1; i <= n; i++)
        cout<<arr[i]<<" ";

    return 0;
}
