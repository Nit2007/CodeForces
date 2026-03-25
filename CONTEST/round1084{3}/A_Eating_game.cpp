#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int;
#define PRINT(v) for(int i1=0;i1<(int)v.size();i1++)cout<<v[i1]<<" ";cout<<endl;
#define N cout<<endl; 

void solve(){//2200A
    int n;cin>>n;
    vector<int>nums(n);
    for(int j=0;j<n;j++){
        cin>>nums[j];
    }
    int maxi = *max_element(nums.begin(),nums.end());
    cout<<count(nums.begin(),nums.end(),maxi);N
}//It doesn't matter who starts first 
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}
