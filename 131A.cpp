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

    string s, m = "";
    cin>>s;
    if((int)s[0] >= 65 && (int)s[0] <= 90)
        m.push_back((char)tolower(s[0]));
    else
        m.push_back((char)toupper(s[0]));
    int i = 1;
    while(s[i] != '\0'){
        if((int)s[i] >= 65 && (int)s[i] <= 90){
            m.push_back(s[i++] + 32);
        }
        else{
            m = s;
            break;
        }
    }
    cout<<m;

    return 0;
}
