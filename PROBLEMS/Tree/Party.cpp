#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
#define PRINT(v) for(int i1=0;i1<(int)v.size();i1++)cout<<v[i1]<<" ";cout<<endl;
#define PRINTS(s,v) cout<<s<<" : ";for(int i1=0;i1<(int)v.size();i1++)cout<<v[i1]<<" ";cout<<endl;
#define N cout<<endl; 

int Levels = 0;
vector<int>nums[2001];
void dfs(int current,int level){
    Levels = max(Levels,level);
    for(int i=0;i<nums[current].size();i++){
        dfs(nums[current][i],level+1);
    }
}
void solve(){//115A
    int n;cin>>n;
    vector<int>temp(n);

    Levels = 0;
    for(int j=0;j<=n;j++){
        nums[j].clear();
    }

    for(int j=0;j<n;j++){
        cin>>temp[j];
    }
    
    for(int i=0;i<n;i++){
        int root = temp[i];
        if(root == -1){//Manager
            nums[0].push_back(i+1);
        }else{//Employee below some manager
            nums[root].push_back(i+1);
        }
    }
    for(int i=0;i<nums[0].size();i++){//DfS on all manager trees
        dfs(nums[0][i],1);
    }
    cout<<Levels;N
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z=1;
    while(z--){ solve();}
}
//Correct IMplementation but the problem is manager arriving after employee
// void solve(){//115A
//     int n;cin>>n;
//     vector<int>nums(n);
//     for(int j=0;j<n;j++){
//         cin>>nums[j];
//     }
//     vector<int>level(n,0);
//     for(int i=0;i<n;i++){
//         if(nums[i] == -1){
//             level[i] = 0;
//         }else{//So it has a manager => find the parent's level +1
//             int parent = nums[i]-1;
//             level[i] = level[parent] + 1;
//         }
//     }//Count the no of Groups where each level is a Group
//     set<int>uniqueGroup(level.begin(),level.end());
//     cout<<uniqueGroup.size();N 
// }

// void solve(){//115A
//     int n;cin>>n;
//     vector<int>nums(n);
//     for(int j=0;j<n;j++){
//         cin>>nums[j];
//     }
//     vector<vector<int>>Groups(n,vector<int>(0));//Size is n , as all nodes are possible to be managers
//     for(int i=0;i<n;i++){
//         if(nums[i] == -1){
//             Groups[0].push_back(i);
//         }else{
//             Groups[nums[i]].push_back(i);
//         }
//     }//Count the no of Groups where each level is a Group
//     int noOfGroups=0;
//     for(vector<int> g: Groups){
//         if(g.size() != 0)noOfGroups++;
//     }
//     cout<<noOfGroups;N
// }