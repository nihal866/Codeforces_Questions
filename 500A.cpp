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

    int n, t;
    cin>>n>>t;
    int arr[n-1];
    for(int i = 0; i < n-1; i++)
        cin>>arr[i];
    int i = 0;
    while(i < t-1)
        i = i + arr[i];
    if(i == t-1)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}
