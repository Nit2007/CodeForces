#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//g++ Target_Practice.cpp -o target.exe
//del *.exe
int main() {//2185C
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--)
    {
        int n;cin>>n;
        set<int>s;
        for(int j=0;j<n;j++)
        {
            int temp;cin>>temp;
            s.insert(temp);
        }
        vector<int>nums(s.begin(),s.end());
        int max_mex=1;
        int consecutive=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] - nums[i-1] == 1){
                consecutive++;
            }else consecutive=1;
            max_mex=max(max_mex,consecutive);
        }
        if(nums.size() == 0){
            cout<<0<<endl;
            continue;
        }
        cout<< max_mex<<endl;
    }
}



// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// //g++ Target_Practice.cpp -o target.exe
// //del *.exe
// int MEX(vector<int>nums){
//     int i=0,j=0,n=nums.size();
//     while(i<n && j<n){
//         j++;
//         if(j>0 && nums[j-1] == nums[j])continue;
//         if(nums[j] != i)return i;
//         i++;
//     }
//     return nums[nums.size()-1]+1;
// }
// int MEX(vector<int>nums,int shift){
//     int i=0,j=0,n=nums.size();
//     while(i<n && j<n){
//         j++;
//         if(j>0 && nums[j-1] == nums[j])continue;
//         if(nums[j] != i+shift)return i;
//         i++;
//     }
//     return nums[nums.size()-1]+1+shift;
// }
// int main() {
//     ios_base::sync_with_stdio(false);   cin.tie(NULL);
//     int z;cin>>z;
//     while(z--)
//     {
//         int n;cin>>n;
//         vector<int>nums(n);
//         for(int j=0;j<n;j++)
//         {
//             cin>>nums[j];
//         }
//         sort(nums.begin(),nums.end());
//         bool found =false;
        
//         int i=0,j=0;
//         while(i<n && j<n){
//             j++;
//             if(i>0 && nums[i-1] == nums[i])continue;
//             if(nums[j] != i){
//                 int mex = MEX(nums);
//                 cout<<mex<<endl;
//                 found=true;
//                 break;            
                
//             }
//             i++;
//         }
        
//         if(!found)
//         cout<<nums[n-1]<<endl;
//         continue;
//     }
// }
