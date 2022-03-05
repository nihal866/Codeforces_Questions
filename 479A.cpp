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

int maxValue(int arr[], int n){
    if(n == 0)
        return 0;
    return max((arr[n-1] + maxValue(arr, n-1)), (arr[n-1] * maxValue(arr, n-1)));
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int arr[3];
    for(int i = 0; i < 3; i++)
        cin>>arr[i];
    int m = maxValue(arr, 3);
    reverse(arr, arr+3);
    cout<<max(m,maxValue(arr, 3));

    return 0;
}
