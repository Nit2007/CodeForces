#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long;

void solve(){//363B
    int n,k;cin>>n>>k;
    vector<int>nums(n);
    for(int j=0;j<n;j++){
        cin>>nums[j];
    }
    int currSum = 0;
    int start=0;
    for(int i=0;i<k;i++){
        currSum += nums[i];
    }
    int minSum = currSum;
    for(int i=k;i<n;i++){
        currSum =  (currSum - nums[i-k] + nums[i])  ;
        if(currSum < minSum ){
            //As we removed i-k ,then start should be i-k+1 
            start = i-k +1 ;
            minSum = currSum;
        }
    }
    cout<<start+1<<endl;//Start is one indexed
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    { solve();}
}
