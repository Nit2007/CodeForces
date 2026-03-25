#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int;
#define PRINT(v) for(int i=0;i<(int)v.size();i++)cout<<v[i]<<" ";cout<<endl;
#define N cout<<endl; 

vector<ll> getDivisors(ll n){
    vector<ll>Result(0);
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            Result.push_back(i);
            if(i != n/i)Result.push_back(n/i);
        }
    }
    sort(Result.begin(),Result.end());
    return Result;
}
void solve(){//2181H
    ll w,h,d,n;
    cin>>w>>h>>d>>n;
    vector<ll>divisors = getDivisors(n);//PRINT(divisors) 
    //( w * h * d ) => Vol
    //( x * y * z ) => n 

    for(auto x: divisors){// x cuts w
        if(w%x != 0)continue;
        for(auto y: divisors){// y cuts h 
            if(h%y != 0)continue;
            ll product = x * y;
            if(product > n || n%product != 0)continue;
            ll z= n / product; 
            if(d%z == 0){ // z cuts d
                cout<<(x-1)<<" "<<(y-1)<<" "<<(z-1);N
                return ;
            }
        }
    }
    cout<<-1;N
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z=1;
    while(z--){ solve();}
}
