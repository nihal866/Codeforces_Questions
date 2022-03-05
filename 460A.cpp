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

    int n, m, i = 1;
    cin>>n>>m;
    while(i <= n){
        if(i%m == 0)
            n++;
        i++;
    }
    cout<<n<<endl;

    return 0;
}
