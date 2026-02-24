#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//g++ Target_Practice.cpp -o target.exe
//del *.exe
void solve(vector<int>nums){
    int n=nums.size();
    int ones = count(nums.begin(),nums.end(),1);
    if(ones == n)cout<<"Alice\n";
    else if(nums[0] == 0 && nums[n-1] == 0)cout<<"Bob\n";
    else cout<<"Alice\n";
}
int main() {//2183A
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    for(int Z=0;Z<z;Z++)
    {
        int n;cin>>n;
        vector<int>nums(n);
        for(int j=0;j<n;j++)
        {
            cin>>nums[j];
        }
        solve(nums);
    }
}
/*
ALICE[0][1,1][1,(x,x,0)] , BOB[1][0,1][0,..,0]
IN A SEGMENT OF NUMS [L,R]
IF ALL 1S  => 0
IF AT LEAST ONE ZERO => 1
*/
