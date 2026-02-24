#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long;

void solve(){//2193B
    int n;cin>>n;
    vector<int>nums(n);
    for(int j=0;j<n;j++){
        cin>>nums[j];
    }
    for(int i=0;i<n;i++){
        int want=n-i;
        int pos=-1;
        if(nums[i] == want)continue;
        else{
            for(int j=i+1;j<n;j++){
                if(nums[j] == want){
                    pos = j;
                    break;
                }
            }
            if(pos != -1){
                reverse(nums.begin()+i,nums.begin()+pos+1);
                break;
            }
        }
    }
    for(int i:nums){
        cout<<i<<" ";
    }cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}
