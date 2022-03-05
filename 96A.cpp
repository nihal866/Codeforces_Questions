#include<bits/stdc++.h>
#include<string>
#include<string.h>
#include<cmath>
#include<iterator>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    string s;
    cin>>s;
    bool danger = false;
    int i = 1, cnt = 0;
    while(s[i] != '\0'){
        if(s[i] == s[i-1])
            cnt++;
        else
            cnt = 0;
        if(cnt == 6){
            danger = true;
            break;
        }
        i++;
    }
    if(danger)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
