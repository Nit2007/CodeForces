#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long;

void solve(){//2188A
    int n;cin>>n;
    vector<int>ans(n,-1);
    int small = 1;
    int large = n;
    for(int i=n-1;i>0;i-=2){
        ans[i] = small;
        ans[i-1] = large;
        small++;
        large--;
    }
    if(n%2 != 0){
        ans[0] = small;
    }
    for(int i:ans){
        cout<<i<<' ';
    }cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}
