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

    long n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    long arr[n+1];
    arr[0] = 0;
    for(int i = 1; i <= n; i++)
        arr[i] = arr[i-1] + s[i-1] - 'a' + 1;
    while(q--){
        long l, r;
        cin>>l>>r;
        cout<<arr[r] - arr[l-1]<<endl;
    }

    return 0;
}
