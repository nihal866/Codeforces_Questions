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
        int n, m, rd = -1, bl = -1;
        cin>>n;
        int red[n];
        int sumR = 0, resultR = 0;
        for(int i = 0; i < n; i++){
            cin>>red[i];
            sumR += red[i];
            resultR = max(resultR, sumR);
        }
        cin>>m;
        int blue[m];
        int sumB = 0,resultB = 0;
        for(int i = 0; i < m; i++){
            cin>>blue[i];
            sumB += blue[i];
            resultB = max(resultB, sumB);
        }
        cout<<resultB + resultR<<endl;
    }

    return 0;
}
