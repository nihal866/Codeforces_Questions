#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, cnt = 0;
    cin>>n;
    vector<pair<int, int> > v;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(arr[i]){
            v.push_back(make_pair(cnt, i+1));
            cnt = 0;
        }
        else
            cnt++;
    }
    sort(v.begin(), v.end());
    int f = v[v.size()-1].second - 1;
    int l = f - v[v.size()-1].first;
    for(int i = l; i < f; i++)
        arr[i] = 1;
    int cnt1 = 0;
    for(int i = f; i >= 0; i--){
        if(arr[i])
            cnt1++;
        else
            break;
    }
    cout<<cnt1<<endl;

    return 0;
}
