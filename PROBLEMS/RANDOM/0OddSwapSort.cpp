#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//g++ Target_Practice.cpp -o target.exe
//del *.exe
void solve(){
    int n,k;cin>>n;
    vector<int>a(n);
    for(int j=0;j<n;j++)cin>>a[j];
    
    for(int i=0;i<n-1;i++){
        if(a[i] > a[i+1]){
            if(a[i] %2 == a[i+1]%2){
                cout<<"no"<<endl;
                return;
            }
        }
    }
    cout<<"Yes\n";
}
int main() {//1638B
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--)
    {
        solve();
    }
}
