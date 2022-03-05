#include<bits/stdc++.h>
using namespace std;

bool isNum(char c){
    int num = c - '0';
    if(num>=0 && num<=9)    return true;
    return false;
}

int main(){
    string s;
    cin>>s;
    int num = (isNum(s[0])) ? (s[0]-'0') : 0;
    int sum = 0;
    for(int i = 1; i < s.size(); i++){
        if(isNum(s[i])){
            if(isNum(s[i-1]))   num = num*10 + (s[i]-'0');
            else    num = (s[i]-'0');
        }
        else{
            sum += num;
            num = 0;
            
        }
    }
    if(isNum(s[s.size()-1]))    sum += num;
    cout<<sum<<endl;
}