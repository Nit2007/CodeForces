#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long;

void solve(){//2188B
    int n;cin>>n;
    vector<int>nums(n);
    string num;cin>>num;
    for(int j=0;j<n;j++){
        nums[j] = num[j] - '0';
    }
    int ans = count(nums.begin(),nums.end(),1);
    if(n<= 2){
        cout<<1<<endl;return;
    }
    //If the end has 2 Zeros ,then try adding another one for making it vavlid for a 3Zero Check
    if (nums.front() == 0) nums.insert(nums.begin(), 0);
    if (nums.back() == 0) nums.push_back(0);
    int i=0;
    while(i+2<nums.size()){//Find 3 consecutive zeros
        if(nums[i] == 0 &&  nums[i+1] == 0 && nums[i+2] == 0){
            ans++;
            i += 3;
            continue;
        }
        i++;
    }
    cout<<ans<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}
