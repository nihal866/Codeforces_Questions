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

    string s, ans = "";
    cin>>s;
    int i = 0;
    char dot = '.';
    while(s[i] != '\0'){
        s[i] = tolower(s[i]);
        if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'y'){
            ans.push_back(dot);
            ans.push_back(s[i]);
        }
        i++;
    }
    cout<<ans<<endl;

    return 0;
}
