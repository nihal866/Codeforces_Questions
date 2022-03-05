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

    string s, nya = "";
    cin>>s;
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B')
            i+= 3;
        else{
            nya+= s[i];
            if(s[i+1] == 'W' && s[i+2] == 'U' && s[i+3] == 'B')
                nya+= " ";
            i++;
        }
    }
    cout<<nya;

    return 0;
}
