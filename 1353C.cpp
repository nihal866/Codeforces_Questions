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
        long long n, ind= 0;
        cin>>n;
        if(n != 1){
            for(long long i = 3; i <= n; i += 2){
                ind += ((i/2)*(i-1));
            }
        }
        cout<<ind*4<<endl;
    }



    return 0;
}
