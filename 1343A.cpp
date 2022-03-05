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
        long n, sum = 1, i = 1;
        cin>>n;
        while(true){
            sum += pow(2, i++);
            if(n%sum == 0)
                break;
        }
        cout<<n/sum<<endl;
    }

    return 0;
}
