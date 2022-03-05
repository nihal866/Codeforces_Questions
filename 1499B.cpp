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

bool square(long n){
    long i = 1;
    while(i*i <= n){
        if(i*i == n)
            return true;
        i++;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        string s;
        int index = 0;
        bool possible  = true;
        cin>>s;
        int i = s.size() - 1;
        while(i >= 0){
            if(s[i] == s[i-1] && s[i] == '0'){
                index = i;
                break;
            }
            i--;
        }
        for(int i = index-2; i >= 0; i--){
            if(s[i] == s[i-1] && s[i] == '1'){
                possible = false;
                break;
            }
        }
        if(possible)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
