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
    if(m > n)
        cout<<-1<<endl;
    else if(n == m)
        cout<<n<<endl;
    else{
        int cnt = 0;
        if(n % 2 != 0){
            cnt++;
            n--;
        }
        cnt += n/2;
        if(cnt%m != 0)
            cnt += m - (cnt%m);
        cout<<cnt<<endl;
    }

    return 0;
}
