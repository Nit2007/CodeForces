#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long;

void solve(){//2173B
    int n;cin>>n;
    vector<ll>red(n);
    vector<ll>blue(n);
    for(int j=0;j<n;j++){
        cin>>red[j];
    }
    for(int j=0;j<n;j++){
        cin>>blue[j];
    }
    ll maxi=0,mini=0;//At every iteration we want max and min values ,as the operation may flip anytime
    for(int i=0;i<n;i++){
        ll a=red[i],b=blue[i];
        ll mx = max({maxi-a,b-mini});//max({maxi-a,mini-a,b-maxi,b-mini});
        ll mn = min({mini-a,b-maxi});//min({maxi-a,mini-a,b-maxi,b-mini});

        maxi = mx;
        mini = mn;
    }
    cout<<maxi<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}
//WA on TestCase 3
// map<pair<int,ll>,ll>dp;
// ll f(vector<ll>&red,vector<ll>&blue,int i,int k){
//     if(i == red.size())return k;
//     auto key = make_pair(i,k);
//     if(dp.count(key))return dp[key];

//     ll choose_red = f(red,blue,i+1,k-red[i]);
//     ll choose_blue = f(red,blue,i+1,blue[i]-k);
//     return dp[key]=max(choose_red,choose_blue);
// }
// void solve(){//2173B
//     int n;cin>>n;
//     vector<ll>red(n);
//     vector<ll>blue(n);
//     for(int j=0;j<n;j++){
//         cin>>red[j];
//     }
//     for(int j=0;j<n;j++){
//         cin>>blue[j];
//     }
//     dp.clear();
//     cout<<f(red,blue,0,0)<<endl;
// }