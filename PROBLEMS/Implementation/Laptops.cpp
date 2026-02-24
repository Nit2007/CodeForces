#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long;

void solve(){//456A
    int n;cin>>n;
    vector<vector<int>>a(n,vector<int>(2,-1));
    for(int j = 0; j < n; j++){
        cin >> a[j][0] >> a[j][1];
    }
    //Price(i<j => price[i] <=price[j]) is sorted so check only if(i<j) but quality[i] > quality[j]
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++){
        if(a[i-1][1] > a[i][1]){
            cout<<"Happy Alex\n";
            return;
        }
    }
    cout<<"Poor Alex\n";
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    { solve();}
}
