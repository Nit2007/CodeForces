#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int;
#define PRINT(v) for(int i1=0;i1<(int)v.size();i1++)cout<<v[i1]<<" ";cout<<endl;
#define N cout<<endl; 

void solve(){//2205A
    int n;cin>>n;
    vector<int>nums(n);
    for(int j=0;j<n;j++){
        cin>>nums[j];
    }
    vector<int> prefixMax(n);
    prefixMax[0] = nums[0];
    for(int i=1;i<n;i++){
        prefixMax[i] = max(prefixMax[i-1], nums[i]);
    }
    //Ugly index can never be 0, as all elements as somehow 
    // 1.the max_element stays front ,then the last would be ugly
    // 2.If the last index stays at last , then also last would be still ugly
    int cnt = 0;
    for(int i=0;i<n;i++){
        if((i+1) == prefixMax[i])cnt++;
    }
    if(cnt == 1){
        PRINT(nums)
        return ;
    }
    auto maxDist = max_element(nums.begin(),nums.end());
    int dist = distance(nums.begin(),maxDist);
    swap(nums[0] , nums[dist]);
    PRINT(nums)
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}
