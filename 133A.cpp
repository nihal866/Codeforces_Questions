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

    string s;
    cin>>s;
    bool output = false;
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9'){
            output = true;
            break;
        }
        i++;
    }
    if(output)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
