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
        long long a, b, x, y, prod, n, prod1, prod2;
        cin>>a>>b>>x>>y>>n;
        if((a-x)+(b-y) <= n)
            prod = x*y;
        else{
            long long n1, a1, b1, n2, a2, b2;
            n1 = n2 = n;
            a1 = a2 = a;
            b1 = b2 = b;
            a1 -= n1;
            n1 = 0;
            if(a1 <= x){
                n1 = x - a1;
                a1 = x;
            }
            b1 -= n1;
            prod1 = a1 * b1;
            b2 -= n2;
            n2 = 0;
            if(b2 <= y){
                n2 = y - b2;
                b2 = y;
            }
            a2 -= n2;
            prod2 = a2 * b2;
            prod = min(prod1, prod2);
        }
        cout<<prod<<endl;
    }

    return 0;
}
