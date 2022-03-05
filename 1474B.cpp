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

void SieveOfEratosthenes(int num, vector<long> v) {

}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    vector<long> v;
    v.reserve(100000);
    int num = 21000;
    bool pno[num+1];
    memset(pno, true, sizeof(pno));
    for (int i = 2; i*i <= num; i++) {
        if (pno[i] == true) {
            for (int j = i*2; j <= num; j += i)
                pno[j] = false;
        }
    }
    for (int i = 2; i <= num; i++){
        if (pno[i])
            v.push_back(i);
    }
    while(t--){
        long long d, prod = 1;
        cin>>d;
        int m = 2, i = 0;
        while(m){
            if(v[i] - prod >= d){
                prod *= v[i];
                m--;
            }
            i++;
        }
        cout<<prod<<endl;
    }
    v.clear();

    return 0;
}
