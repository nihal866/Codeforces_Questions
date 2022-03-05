#include<bits/stdc++.h>
#include<iostream>
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

    int n, k;
    cin>>n>>k;
    string s, m = "PRINT ";
    cin>>s;
    if(k != 1 && k != n){
        if(k <= n/2){
            for(int i = 0; i <= (n/2 - k); i++){
                cout<<"LEFT"<<endl;
            }
            k = 1;
        }
        else{
            for(int i = 0; i <= (k - n/2); i++){
                cout<<"RIGHT"<<endl;
            }
            k = n;
        }
    }
    if(k == 1){
        for(int i = 0; i < n-1; i++){
            m.push_back(s[i]);
            cout<<m<<endl;
            cout<<"RIGHT"<<endl;
            m.erase(m.end() - 1);
        }
        m.push_back(s[n-1]);
        cout<<m<<endl;
    }
    if(k == n){
        for(int i = n-1; i > 0; i--){
            m.push_back(s[i]);
            cout<<m<<endl;
            cout<<"LEFT"<<endl;
            m.erase(m.end() - 1);
        }
        m.push_back(s[0]);
        cout<<m<<endl;
    }

    return 0;
}
