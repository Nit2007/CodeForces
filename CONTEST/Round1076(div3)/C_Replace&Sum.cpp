#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long;

void solve(){//2193C
    int n,q;cin>>n>>q;
    vector<int>a(n);
    vector<int>b(n);
    for(int j=0;j<n;j++){cin>>a[j];}
    for(int j=0;j<n;j++){cin>>b[j];}
    //BEST_VALUE at a[i] = {a[i],b[i], Best_Value at right a[i+1]}
    vector<int>mx(n);
    mx[n-1] = max(a[n-1],b[n-1]);
    for(int i=n-2;i>=0;i--){
        mx[i] = max({a[i],b[i],mx[i+1]});
    }
    vector<int>pref(n+1,0);
    for(int i=0;i<n;i++){
        pref[i+1] = pref[i] + mx[i];
    }


    for(int j=0;j<q;j++){
        int l,r;
        cin>>l>>r;
        l--;r--;
        cout<<pref[r+1]-pref[l]<<" ";
    }cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}
