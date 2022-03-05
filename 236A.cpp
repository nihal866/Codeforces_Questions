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

    int n, m, val;
    cin>>n>>m;
    int arr[n];
    vector<int> v;
    v.reserve(100001);
    for(int i = 0; i < n; i++){
        cin>>val;
        v.push_back(val);
    }
    vector<int>::iterator ip;
    ip = v.begin();
    cout<<*(ip + 2);

    return 0;
}
