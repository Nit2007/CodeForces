#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long;

void solve(){//2193D
    int n;cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    for(int j=0;j<n;j++){cin>>a[j];}
    for(int j=0;j<n;j++){cin>>b[j];}

    sort(a.begin(),a.end(),greater<int>());
    int totalSword = 0 , level = 0;
    ll score=0;
    for(int i=0;i<n;i++){
        while(level < n && (totalSword) + b[level] <= i+1){//i+1 - No of usable swords after sorting
            totalSword += b[level] ;
            level++;
        }
        score = max(score , 1LL * level * a[i]);//level * x
    }
    cout<<score<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}
