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

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int, int> mp;
        int a, x;
        for(int i = 0; i < n; i++){
            cin>>a;
            if(mp.find(a) != mp.end())
                mp[a]++;
            else
                mp.insert({a, 1});
        }
        a = mp.size();
        vector<int> v;
        map<int, int>::iterator itr;
        itr = mp.begin();
        while(itr != mp.end()){
            v.push_back(itr->second);
            itr++;
        }
        sort(v.begin(), v.end(), greater<int>());
        if(n == 1)
            x = 0;
        else if(a == n)
            x = 1;
        else if(a > v[0])
            x = v[0];
        else if(a < v[0])
            x = a;
        else
            x = a-1;

        cout<<x<<endl;
    }

    return 0;
}
