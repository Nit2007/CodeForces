#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long;

void Print(int n){
    if(n == 0){
        cout<<0<<endl;
        return;
    }
    for(int i=0;i<=n;i++){
        cout<<i;
        cout<<' ';
    }for(int i=n-1;i>=0;i--){
        cout<<i;
        if(i!=0)cout<<' ';
    }cout<<endl;
}
void Space(int n){
    for(int i=0;i<n;i++){
        cout<<" ";
    }
}
void solve(){//118B
    int n;cin>>n;
    for(int i=0;i<=n;i++){
        Space(2 * (n-i));
        Print(i);
    }
    for(int i=n-1;i>=0;i--){
        Space(2 * (n-i));
        Print(i);
    }
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    { solve();}
}
