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

bool sortcol( const vector<int>& v1, const vector<int>& v2 ) {
    return v1[0] < v2[0];
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int s, n, y, x;
    bool paas = true;
    cin>>s>>n;
    vector< vector<int> > v;
    vector<int> v1;
    for(int i = 0; i < n; i++){
        cin>>x>>y;
        v1.push_back(x);
        v1.push_back(y);
        v.push_back(v1);
        v1.clear();
    }
    sort(v.begin(), v.end(), sortcol);
    for(int i = 0; i < n; i++){
        if(s > v[i][0])
            s += v[i][1];
        else{
            paas = false;
            break;
        }
    }
    if(paas)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}
