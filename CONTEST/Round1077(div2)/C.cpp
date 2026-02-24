#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long;

void solve(){//2188C
    int n;cin>>n;
    vector<int>nums(n);
    for(int j=0;j<n;j++){
        cin>>nums[j];
    }
    if(is_sorted(nums.begin(),nums.end())){
        cout<< -1<<endl;return;
    }
    int piggy = 0;
    for(int i=0;i<n-1;i++){
        if(nums[i] > nums[i+1]){
            piggy = max(piggy,nums[i] - nums[i+1]);
            swap(nums[i],nums[i+1]);
        }
    }
    cout<<piggy<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}
