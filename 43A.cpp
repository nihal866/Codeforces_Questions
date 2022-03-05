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

    string team, t1 = "", t2 = "";
    int n, a = 0, b = 0;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>team;
        if(i == 1)
            t1 = team;
        if(t1 == team)
            a++;
        else{
            b++;
            t2 = team;
        }
    }
    if(a>b)
        cout<<t1<<endl;
    else
        cout<<t2<<endl;

    return 0;
}
