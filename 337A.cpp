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

    int n, m, a, mi = INT_MAX;
    cin>>n>>m;
    vector<int> v, u;
    v.reserve(100);
    u.reserve(100);
    for(int i = 0; i < m; i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i <= m-n; i++){
        u.push_back(v[i+n-1] - v[i]);
    }
    sort(u.begin(), u.end());
    cout<<u[0]<<endl;


    return 0;
}
