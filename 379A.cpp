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

    int a, b;
    cin>>a>>b;
    int sum = a;
    int rem = 0;
    while(a >= b){
        sum += a/b;
        rem = a % b;
        a /= b;
        a += rem;
    }
    cout<<sum<<endl;

    return 0;
}
