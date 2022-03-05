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

    long n, m, a;
    long long area, len, bre;
    cin>>n>>m>>a;
    len = n/a;
    bre = m/a;
    if(n % a != 0)
        len++;
    if(m % a != 0)
        bre++;
    area = len*bre;
    cout<<area;

    return 0;
}
