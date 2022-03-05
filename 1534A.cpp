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

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        char ch[n][m];
        int red = 2, white = 2;
        bool err = false;
        bool found = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>ch[i][j];
                if(ch[i][j] != '.'){
                    if(ch[i][j] == 'R'){
                        if(red == 2)
                            red = (i+j) % 2;
                    }
                    else{
                        if(white == 2)
                            white = (i+j) % 2;
                    }
                }
                if(ch[i][j] == 'R'){
                    if((i+j)%2 != red)
                        err = true;
                }
                if(ch[i][j] == 'W'){
                    if((i+j)%2 != white)
                        err = true;
                }
            }
        }
        if(err)
            cout<<"NO"<<endl;
        else if(red == white)
            cout<<"NO"<<endl;
        else if(red != white){
            cout<<"YES"<<endl;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if((i+j)%2 == red)
                        cout<<'R';
                    else
                        cout<<'W';
                }
                cout<<endl;
            }
        }
    }

    return 0;
}

