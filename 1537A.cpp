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

    int t;
    cin>>t;
    while(t--){
        int n;
        long sum = 0, val;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            sum += arr[i];
        }
        if(sum == n)
            val = 0;
        else if(sum < n)
            val = 1;
        else
            val = sum - n;
        cout<<val<<endl;
    }

    return 0;
}
