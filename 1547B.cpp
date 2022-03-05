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

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        bool possible = true;
        int n = s.size();
        int l = 0, r = n-1;
        while(n--){
            char c = (char)(97+n);
            if(s[l]==c || s[r]==c){
                if(s[l]==c)
                    l++;
                else
                    r--;
            }
            else{
                possible = false;
                break;
            }
        }
        if(possible)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
