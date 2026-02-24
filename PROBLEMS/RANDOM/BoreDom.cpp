#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 100001
//g++ Target_Practice.cpp -o target.exe
//del *.exe
void solve(){
    int n;cin>>n;
    vector<int>nums(n);
    for(int j=0;j<n;j++)
        {
            cin>>nums[j];
        }
    vector<ll>count(N,0);
    for(int x:nums){
        count[x]++;
    }
    vector<ll>dp(N,0);//dp[i] - max value till i
    dp[1] = count[1];
    for(int i=2;i<N;i++){ //skip || take
        dp[i] = max(dp[i-1],dp[i-2] + (i * count[i]));
    }
    cout<< dp[N-1];
}
int main() {//455A
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    solve();
    
}
