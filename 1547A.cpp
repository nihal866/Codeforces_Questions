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
        int ax, ay, bx, by, fx, fy, dist = 0;
        cin>>ax>>ay>>bx>>by>>fx>>fy;
        dist += abs(ax - bx);
        dist += abs(ay - by);
        if((ax==bx && fx==ax) && (fy<max(ay,by) && fy>(min(ay,by))))
            dist += 2;
        else if((ay==by && fy==ay) && (fx<max(ax,bx) && fx>(min(ax,bx))))
            dist += 2;
        cout<<dist<<endl;
    }

    return 0;
}
