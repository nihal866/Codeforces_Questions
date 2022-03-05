 #include <bits/stdc++.h>
    using namespace std;
 
    #define ll long long
    #define mod 998244353
 
 
 
    int main() {
 
    
 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
 
        int n=1000009;
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
 
        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        vector<int> x;
        for(int i=2;i<n;i++){
            if(prime[i]==true){
                x.push_back(i);
            }
        }
 
        int t;
        cin>>t;
        while(t--){
            ll a,b,k;
            cin>>a>>b>>k;
            if(k==1){
                if(a==1 && b==1){
                    cout<<"NO\n";
                    continue;
                }
                if(a==b){
                    cout<<"NO\n";
                    continue;
                }
                if(a%b==0 || b%a==0){
                    cout<<"YES\n";
                }
                else{
                    cout<<"NO\n";
                }
                continue;
            }
            ll sum=0;
 
 
                while (a%2 == 0)
                {
                    a = a/2;
                    sum++;
                }
 
                for (int i = 0; x[i]<= sqrt(a) && i<x.size(); i++)
                {
                    while (a%x[i] == 0)
                    {
                        sum++;
                        a = a/x[i];
                    }
                }
 
                if (a > 2){
                    sum++;
                }
 
                while (b%2 == 0)
                {
                    b = b/2;
                    sum++;
                }
 
                for (int i = 0; x[i] <= sqrt(b) && i<x.size(); i++)
                {
                    while (b%x[i] == 0)
                    {
                        sum++;
                        b = b/x[i];
                    }
                }
 
                if (b > 2){
                    sum++;
                }
 
            if(k<=sum){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
 
        }
 
 
        return 0;
 
    }