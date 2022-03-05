#include<bits/stdc++.h>
using namespace std;

int sparseTable[100][10];
void rangeQueries(int arr[], int n){
    for(int i = 0; i < n; i++)  sparseTable[i][0]=arr[i];
    for(int j = 1; j <= log2(n); j++){
        for(int i = 0; i+(1<<j) <= n; i++){
            sparseTable[i][j] = sparseTable[i][j-1] + sparseTable[i + (1 << j-1)][j-1];
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)  cin>>arr[i];
    int q;
    cin>>q;
    rangeQueries(arr, n);
    int k = log2(n);
    while(q--){
        int l, r;
        cin>>l>>r;
        long long sum = 0;
        for(int i = k; i >= 0; j--){
            if((1 << j) <= 
        }
    }
}