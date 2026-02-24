#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//g++ Target_Practice.cpp -o target.exe
//del *.exe
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    vector<int>b(n);
    for(int j=0;j<n;j++)cin>>a[j];
    for(int j=0;j<n;j++)cin>>b[j];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<int>());
    int j=0;
    for(int i=0;i<k;i++)
    {
        if(a[i] <b[i]){
            swap(a[i],b[i]);
        }else break;
    }
    cout<<accumulate(a.begin(),a.end(),0)<<endl;
}
int main() {//1353B
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--)
    {
        solve();
    }
}
