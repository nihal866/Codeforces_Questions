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

    long n;
    cin>>n;
    vector< pair<long long, long long> > v;
    v.reserve(110000);
    long long a, b;
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        v.push_back(make_pair(b, a));
    }
    long l = 0, r = n-1;
    long long price = 0, prod = 0;
    sort(v.begin(), v.end(), sortbysec);
    while(l <= r){
        while(prod < v[l].first && l <= r){
            if(v[r].second <= (v[l].first)-prod){
                long long addon = v[r].second;
                prod += addon;
                price += 2*addon;
                r--;
            }
            else{
                long long addon = v[l].first - prod;
                prod += addon;
                price += 2*addon;
                v[r].second -= addon;
            }
        }
        while(prod >= v[l].first && l <= r){
            price += v[l].second;
            prod += v[l].second;
            l++;
        }
    }
    cout<<price<<endl;

    return 0;
}
