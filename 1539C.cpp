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

    long long n, k, x, vn;
    cin>>n>>k>>x;
    vector<long long> v;
    v.reserve(200000);
    vector<long long> d;
    d.reserve(200000);
    for(long i = 0; i < n; i++){
        cin>>vn;
        v.push_back(vn);
    }
    sort(v.begin(), v.end());
    for(long i = 1; i < n; i++){
        if(abs(v[i] - v[i-1]) > x)
            d.push_back(v[i] - v[i-1]);
    }
    long cnt = d.size() + 1;
    sort(d.begin(), d.end());
    for(long i = 0; i < d.size(); i++){
        if(k <= 0)
            break;
        if(d[i]%x == 0){
            if(d[i]/x > k+1)
                break;
            else{
                k -= d[i]/x;
                k++;
                cnt--;
            }
        }
        else{
            if(d[i]/x > k)
                break;
            else{
                k -= d[i]/x;
                cnt--;
            }
        }
    }
    cout<<cnt<<endl;


    return 0;
}
