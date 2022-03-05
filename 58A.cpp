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

    int n, m = 0, i = 0;
    bool hello = false;
    string s, h = "hello";
    cin>>s;
    while(s[i] != '\0'){
        if(h[m] == s[i])
            m++;
        if(m == 5){
            hello = true;
            break;
        }
        i++;
    }
    if(hello)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}
