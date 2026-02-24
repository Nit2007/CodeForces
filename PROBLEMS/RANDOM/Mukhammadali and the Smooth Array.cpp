#include <bits/stdc++.h>
using namespace std;

int f(int i,vector<int>nums,vector<int>cost){
    int n=nums.size();
    if(i==n) return 0;
    if(i+1 < n && nums[i] > nums[i+1])
    {
        int change_i = cost[i]+f(i+1,nums,cost);
        int change_i1= cost[i+1]+f(i+1,nums,cost);
        return min(change_i,change_i1); 
    }
    return f(i+1,nums,cost);
}
int main() {
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int m;cin>>m;
        vector<int>cost(m),nums(m);
        for(int j=0;j<m;j++)
        {
            cin>>nums[j];
        }
        for(int j=0;j<m;j++)
        {
            cin>>cost[j];
        }
        cout<<f(0,nums,cost);
    }
}
/*10
1
10
5
4
1 2 2 3
5 6 7 8
4
4 3 2 1
1 1 1 1
3
3 1 2
100 1 1
5
5 5 5 5 5
10 1 10 1 10
5
1 3 2 2 4
100 1 1 1 100
6
10 9 8 7 6 5
1 100 1 100 1 100
5
100 1 100 100 100
1 100 1 1 1
4
2 1 2 1
5 4 3 2
7
1 5 3 4 2 6 7
10 1 10 1 10 1 10
 */