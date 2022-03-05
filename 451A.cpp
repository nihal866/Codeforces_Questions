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

    int n, m, c;
    cin>>n>>m;
    c = min(n, m);
    if(c % 2 == 0)
        cout<<"Malvika"<<endl;
    else
        cout<<"Akshat"<<endl;

    return 0;
}
