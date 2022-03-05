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

    int n;
    cin>>n;
    bool happy = false;
    while(n--){
        int x, y;
        cin>>x>>y;
        if(x != y)
            happy = true;
    }
    cout<<(happy ? "Happy Alex" : "Poor Alex")<<endl;

    return 0;
}
