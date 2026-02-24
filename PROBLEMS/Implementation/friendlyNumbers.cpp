#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long;

int d(int y){
    string num = to_string(y);
    int sum=0;
    for(int i=0;i<(int)num.length();i++){
        sum += (num[i] - '0');
    }
    return sum;
}
void solve(){//2197A
    int n;cin>>n;
    int count = 0;
    for(int y=n;y<=n+200;y++){
        if(y - d(y) == n){
            // cout<<y<<" ";
            count ++;
        }
    }
    cout<<count<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}
