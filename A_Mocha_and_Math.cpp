#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
    cin>>n;
    long arr[n];
    long m = 0;
    for(int i = 0; i < n; i++)  cin>>arr[i];
    m = arr[0];
    for(int i = 1; i < n; i++)    m=m&arr[i];
    cout<<m<<endl;
    }
}