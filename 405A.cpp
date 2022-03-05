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

    int n, a;
    cin>>n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
        cout<<v[i]<<" ";

    return 0;
}
