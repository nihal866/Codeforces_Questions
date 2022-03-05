#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m;
    cin>>n;
    vector<long> v;
    vector<long>::iterator itr;
    long a, sum = 0;
    for(int i = 0; i < n; i++){
        cin>>a;
        sum += a;
        v.push_back(sum);
    }
    cin>>m;
    long f[m];
    for(int i = 0; i < m; i++)
        cin>>f[i];
    for(int i = 0; i < m; i++){
        itr = lower_bound(v.begin(), v.end(), f[i]);
        cout<<(itr - v.begin() + 1)<<endl;
    }

    return 0;
}
