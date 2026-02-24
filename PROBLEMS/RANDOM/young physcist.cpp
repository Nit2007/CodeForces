#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int>x(n),y(n),z(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
        cin>>y[i];
        cin>>z[i];
    }
    int X = accumulate(x.begin(),x.end(),0);
    int Y = accumulate(y.begin(),y.end(),0);
    int Z = accumulate(z.begin(),z.end(),0);

    if (X == 0 && Y == 0 && Z == 0)
        cout << "YES";
    else cout<<"NO";
}