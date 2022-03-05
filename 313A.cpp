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

    long n;
    cin>>n;
    if(n > 0)
        cout<<n<<endl;
    else{
        n = abs(n);
        int n1 = n / 10;
        int n2 = (n / 100)*10 + (n % 10);
        cout<<(min(n1, n2) * -1)<<endl;
    }

    return 0;
}
