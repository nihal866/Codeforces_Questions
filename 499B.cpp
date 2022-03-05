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

    vector<string> v;
    string s1, s2;
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < 2*m; i += 2){
        cin>>s1>>s2;
        v.push_back(s1);
        v.push_back(s2);
    }
    vector<string> sent;
    string s;
    for(int i = 0; i < n; i++){
        cin>>s;
        sent.push_back(s);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2*m; j += 2){
            if(v[j] == sent[i]){
                if(v[j].size() > v[j+1].size())
                    sent[i] = v[j+1];
                break;
            }
        }
        cout<<sent[i]<<" ";
    }

    return 0;
}
