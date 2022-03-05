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

long operate(long a, long b, long c){
    if(a == 0)
        return 0;
    if(b == c)
        return (1 + min(operate(a/b, b, c), operate(a/++b, b, c)));
    else{
        c = b;
        return (2 + min(operate(a/b, b, c), operate(a/++b, b, c)));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        long a, b, operations = 0;
        cin>>a>>b;
        operations = operate(a, b, b);
        cout<<operations<<endl;
    }

    return 0;
}
