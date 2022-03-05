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
    int arr[5] = {0};
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>t;
        arr[t]++;
    }
    long taxis = 0;
    taxis += arr[4] + arr[3];
    if(arr[1] > arr[3])
        arr[1] -= arr[3];
    else
        arr[1] = 0;
    taxis += arr[2]/2;
    if(arr[2]%2 != 0){
        taxis++;
        if(arr[1])
            arr[1] -= 2;
    }
    if(arr[1] > 0){
        taxis += arr[1]/4;
        if(arr[1]%4 != 0)
            taxis++;
    }
    cout<<taxis<<endl;

    return 0;
}
