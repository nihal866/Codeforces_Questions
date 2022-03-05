#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> odd;
    vector<int> even;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(arr[i]%2==0)
            even.push_back(i+1);
        else
            odd.push_back(i+1);
    }
    if(odd.size() == 1)
        cout<<odd[0];
    else if(even.size() == 1)
        cout<<even[0];

    return 0;
}
