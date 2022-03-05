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

bool sortbysec(const pair<long long, long long> &a,
              const pair<long long, long long> &b)
{
    return (a.first < b.first);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    long long t;
    cin>>t;
    while(t--){
        vector< pair<long long, long long> > v;
        long long n, a;
        cin>>n;
        for(long long i = 0; i < n; i++){
            cin>>a;
            v.push_back(make_pair(a, i+1));
        }
        long long cnt = 0;
        sort(v.begin(), v.end(), sortbysec);
        for(long long i = 0; i < n; i++){
            long long m = ((2*n)-1) / v[i].first;
            long long j = i+1;
            while(v[j].first <= m){
                if(v[i].first*v[j].first == (v[i].second + v[j].second))
                    cnt++;
                j++;
            }
        }
        cout<<cnt<<endl;

    }

    return 0;
}
