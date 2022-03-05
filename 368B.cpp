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

    int n, m;
    cin>>n>>m;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    set<int> s;
    for(int i = n-1; i>= 0; i--){
        s.insert(arr[i]);
        arr[i] = s.size();
    }
    while(m--){
        int x;
        cin>>x;
        cout<<arr[x-1]<<endl;
    }

    return 0;
}
