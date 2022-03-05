#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1000000;
bool isPrime[N];
set<int> s;

void preCalculatorPrime(){
    fill(isPrime+2, isPrime+N, true);
    for(int i = 2; i*i < N; i++){
        for(int j = i*i; j < N; j=j+i)
            isPrime[j] = false;
    }
    for(int i = 2; i < N; i++){
        if(isPrime[i])
            s.insert(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    preCalculatorPrime();
    while(t--){
        ll a;
        cin>>a;
        double b = sqrt(a);
        if(a == 1)
            cout<<"NO"<<endl;
        else if(ceil(b) == floor(b)){
            if(s.find(b) == s.end())
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
