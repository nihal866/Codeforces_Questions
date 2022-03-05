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
        long long int n,x,t;
        cin>>n>>x>>t;
        long long sum=0;
        int i=1;
        while(1)
        {
            long long int v=t/x;
            if(n-i<=t/x)
            {
                sum += ((n-i)*(n-i+1))/2;
                break;
            }
            int inc = min(n-i,v);
            sum += inc;
            if(inc == 0)
                break;
            i++;
        }
        cout<<sum<<endl;
    }

    return 0;
}
