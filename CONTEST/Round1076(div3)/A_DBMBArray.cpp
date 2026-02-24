#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long;

void solve(){//2193A
    int n,s,x;cin>>n>>s>>x;
    vector<int>nums(n);
    int sum=0;
    for(int j=0;j<n;j++){
        cin>>nums[j];
        sum+=nums[j];
    }
    while(sum < s){
        sum += x;
    }
    if(sum == s)cout<<"YES";
    else cout<<"NO";
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}
