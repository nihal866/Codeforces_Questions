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

int max3(int a, int b, int c){
    if(a > b)
        return (a > c) ? a : c;
    else
        return (b > c) ? b : c;
}



int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, a, b, c;
    cin>>n>>a>>b>>c;
    int ans = 0, z;
    for(int i = 0; i <= 4000; i++){
        for(int j = 0; j <= 4000; j++){
            z = n - (i*a + j*b);
            if(z<0)
                break;
            if(z%c == 0){
                ans = max(ans, i + j + z/c);
            }
        }
    }
    cout<<ans;

    return 0;
}
