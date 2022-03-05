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

void check(string s, int n){
    int left = 0, right = 0, mark = 0, i = 0;
    while(i < n){
        if(s[i] == '(')
            left++;
        else if(s[i] == ')')
            right++;
        else
            mark++;

        if(right > left && right > mark){
            cout<<"NO"<<endl;
            return;
        }
        i++;
    }
    cout<<"YES"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        if(n % 2 != 0)
            cout<<"NO"<<endl;
        else{
            if(s[0] == ')')
                cout<<"NO"<<endl;
            else if(s[n-1] == '(')
                cout<<"NO"<<endl;
            else
                check(s, n);
        }
    }

    return 0;
}
