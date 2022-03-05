#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    long n, val;
    vector<long> v;
    cin>>n;
    for(long i = 0; i < n; i++){
        cin>>val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    long m;
    cin>>m;
    long arr[m];
    for(long i = 0; i < m; i++)
        cin>>arr[i];
    vector<long>::iterator itr;
    for(long i = 0; i < m; i++){
        itr = upper_bound(v.begin(), v.end(), arr[i]);
        cout<<(itr - v.begin())<<endl;
    }

    return 0;
}
