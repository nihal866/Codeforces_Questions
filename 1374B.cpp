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
        long n, cnt = 0;
        cin>>n;
        while(n != 1){
            if(n%6 == 0){
                n = n/6;
                cnt++;
            }
            else if(n%3 == 0){
                n *= 2;
                cnt++;
            }
            else{
                cnt = -1;
                break;
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}
