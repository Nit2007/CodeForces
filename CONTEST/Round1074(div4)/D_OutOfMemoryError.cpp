#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//g++ Target_Practice.cpp -o target.exe
//del *.exe
void clear(vector<ll>&nums,vector<pair<int,ll>>&op){
    for(auto o:op){
        nums[o.first]-=o.second;
    }
    op = {};
}
int main() {//2185D
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--)
    {
        int n,m,h;cin>>n>>m>>h;
        vector<ll>nums(n);
        for(int j=0;j<n;j++)
        {
            cin>>nums[j];
        }
        vector<ll>orginal = nums;
        vector<pair<int,ll>>changed;
        int b=0;
        ll c=0;
        for(int i=0;i<m;i++){
            cin>>b>>c;
            nums[b-1]+=c;
            changed.push_back({b-1,c});
            if(nums[b-1] > h){
                clear(nums,changed);
                // nums = orginal;
            }
        }
        for(int i:nums){
            cout<<i<<' ';
        }cout<<endl;
    }
}
