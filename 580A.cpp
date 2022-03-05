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

    int n, cnt = 1;
    cin>>n;
    vector<int> v;
    v.reserve(100000);
    long arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    for(int i = 1; i < n; i++){
        if(arr[i] >= arr[i-1]){
            cnt++;
            continue;
        }
        v.push_back(cnt);
        cnt = 1;
    }
    v.push_back(cnt);
    sort(v.begin(), v.end(), greater<int>());
    cout<<v[0]<<endl;

    return 0;
}
