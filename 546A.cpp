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

    long n, k, w;
    cin>>k>>n>>w;
    long total = (k * w *(w+1)) / 2;
    if(total > n)
        cout<<total-n<<endl;
    else
        cout<<0<<endl;

    return 0;
}
