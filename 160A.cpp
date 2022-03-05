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

    vector<int> v;
    v.reserve(100);
    int a, n, sum = 0, total = 0, cnt = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a;
        total += a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    while(sum <= total/2){
        n--;
        sum += v[n];
        cnt++;
    }
    cout<<cnt;

    return 0;
}
