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

    bool lucky = false;
    int n;
    cin>>n;
    int arr[12] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 777};
    for(int i = 0; i < 12; i++){
        if(n%arr[i] == 0){
            lucky = true;
            break;
        }
    }
    if(lucky)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}
