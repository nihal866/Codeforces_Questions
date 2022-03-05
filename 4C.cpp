#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    map<string, int> mp;
    map<string, int>::iterator itr;
    while(t--){
        string s;
        cin>>s;
        if(mp.find(s)==mp.end()){
            mp.insert({s, 0});
            cout<<"OK"<<endl;
        }
        else{
            itr = mp.find(s);
            itr->second++;
            cout<<s<<itr->second<<endl;
        }
    }

    return 0;
}
