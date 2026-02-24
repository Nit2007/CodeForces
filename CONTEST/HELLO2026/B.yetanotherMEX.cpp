#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//g++ Target_Practice.cpp -o target.exe
//del *.exe
/*
MEX either decreases or stays the same for every deletion
so to get max MEX we need to preserve it by deleting Junks(duplicate,caps) which dont affect the value
According to Pigeon Hole principle in every window of size k ,there would be some Junk ,
because As long as the array length ≥ k, every window of size k MUST contain junk.
 */
void solve(){
    int n,k;cin>>n>>k;
    vector<int>nums(n);
    for(int j=0;j<n;j++)
    {
        cin>>nums[j];
        nums[j] = min(nums[j],n+1);//Cap bigger numbers to n+1
    }
    vector<int>freq(n+2,0);
    for(int i=0;i<n;i++){
        freq[nums[i]]++;
    }
    int mex=0;
    while(freq[mex])mex++;//Find the first missing value
    cout<<min(mex,k-1)<<endl;//Either it could be the first missing value or the size of the final state
}
int main() {//2183B
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--)
    {
        solve();
    }
}
// int MEX(vector<int>nums){
//     sort(nums.begin(),nums.end());
//     for(int i=0;i<nums.size();i++){
//         if(nums[i] != i)return i;
//     }
//     return nums[nums.size()-1]+1;
// }
// int main() {
//     ios_base::sync_with_stdio(false);   cin.tie(NULL);
//     int n;cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         int m;cin>>m;
//         vector<int>nums(m);
//         int k;cin>>k;
//         for(int j=0;j<m;j++)
//         {
//             cin>>nums[j];
//         }
//         while(nums.size() >= k){
//             int mex = INT_MIN;
//             int W=0;
//             for(int wind=0;wind+k<=m;wind++){
//                 vector<int>temp (nums.begin()+wind,nums.begin()+wind+k);
//                 if(mex < MEX(temp)){
//                     W = wind;
//                 }
//             }
//             remove(nums.begin()+W,nums.begin()+k,mex);
//         }
//         cout<<MEX(nums)<<endl;
//     }
// }
