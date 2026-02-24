#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//g++ Target_Practice.cpp -o target.exe
//del *.exe
int main() {//2185B
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--)
    {
        int n;cin>>n;
        vector<int>nums(n);
        for(int j=0;j<n;j++)
        {
            cin>>nums[j];
        }
        int mx=*max_element(nums.begin(),nums.end());
        cout<<mx*n<<endl;
    }
}
