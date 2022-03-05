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
        int n, zero = 0, one = 0, two = 0, operations = 0;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            if(arr[i] % 3 == 0)
                zero++;
            if(arr[i] % 3 == 1)
                one++;
            if(arr[i] % 3 == 2)
                two++;
        }
        while(1){
            if(zero > n/3){
                operations += zero - n/3;
                one += zero - n/3;
                zero = n/3;
            }
            else if(one > n/3){
                operations += one - n/3;
                two += one - n/3;
                one = n/3;
            }
            else if(two > n/3){
                operations += two - n/3;
                zero += two - n/3;
                two = n/3;
            }
            else
                break;
        }
        cout<<operations<<endl;
    }

    return 0;
}
