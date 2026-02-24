#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//2180A
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int l,a,b;
        cin>>l>>a>>b;
        int n=1;
        int maxi= 0;
        while(true){
            int curr = (a + (n*b))%l;
            maxi = max(curr,maxi);
            if(curr == a)break;
            n++;
        }
        cout<<maxi<<endl;
    }
}
