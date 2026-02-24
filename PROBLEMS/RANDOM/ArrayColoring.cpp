#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//g++ Target_Practice.cpp -o target.exe
//del *.exe
void solve(){//2191A
    int n;cin>>n;
    vector<int>nums(n);
    for(int j=0;j<n;j++){
        cin>>nums[j];
    }
    map<int,bool>color;
    bool t=false;
    for(int i=0;i<n;i++){
        color[nums[i]] = t;
        t = !t;
    }
    sort(nums.begin(),nums.end());
    for(int i=1;i<n;i++){
        if(color[nums[i-1]] == color[nums[i]]){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}
