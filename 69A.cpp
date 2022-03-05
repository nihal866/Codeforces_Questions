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

    int n, sumx = 0, sumy = 0, sumz = 0;
    cin>>n;
    int arr[n][3];
    for(int i = 0; i < n; i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        sumx += arr[i][0];
        sumy += arr[i][1];
        sumz += arr[i][2];
    }
    if(sumx == 0 && sumy == 0 && sumz == 0)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}
