#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        int n, a = 0, b = 0;
        bool poss = false;
        cin>>n;
        string s;
        cin>>s;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a') a++;
            else    b++;
            if(a && b){
                cout<<i<<" "<<(i+1)<<endl;
                poss = true;
                break;
            }
        }
        if(!poss)   cout<<"-1 -1"<<endl;
    }
    return 0;
}