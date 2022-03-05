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
        int n, x;
        cin>>n;
        bool poss = false;
        vector<int> v;
        v.reserve(100);
        vector<int> even;
        even.reserve(100);
        vector<int> odd;
        odd.reserve(100);
        for(int i = 0; i < n; i++){
            cin>>x;
            v.push_back(x);
            if(x%2 == 0)
                even.push_back(x);
            else
                odd.push_back(x);
        }
        if(even.size()%2==0 && odd.size()%2==0)
            poss = true;
        else{
            sort(v.begin(), v.end());
            for(int i = 1; i < n; i++){
                if(v[i] - v[i-1] == 1){
                    poss = true;
                    break;
                }
            }
        }
        cout<<((poss)?"YES":"NO")<<endl;
    }

    return 0;
}
