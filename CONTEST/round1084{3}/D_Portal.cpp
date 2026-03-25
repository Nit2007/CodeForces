#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int;
#define PRINT(v) for(int i1=0;i1<(int)v.size();i1++)cout<<v[i1]<<" ";cout<<endl;
#define PRINTS(s,v) cout<<s<<" : ";for(int i1=0;i1<(int)v.size();i1++)cout<<v[i1]<<" ";cout<<endl;
#define N cout<<endl; 

void solve(){//2200D
    int n,x,y;cin>>n>>x>>y;
    vector<int>nums(n);
    for(int j=0;j<n;j++){
        cin>>nums[j];
    }
    vector<int> Portal(nums.begin()+x,nums.begin()+y);
    auto min_index = min_element(Portal.begin(),Portal.end());
    int shift = distance(Portal.begin(),min_index);

    // PRINT("Portal" ,Portal);
    rotate(Portal.begin(), Portal.begin() + shift, Portal.end());
    // PRINT("Rotated" ,Portal);
    vector<int>NonPortal(0);
    for(int i=0;i<n;i++){
        if(x <= i && i < y)continue;
        NonPortal.push_back(nums[i]);
    }

    vector<int>Result(0);

    for(int i=0;i<NonPortal.size();i++){
        if(Portal[0] < NonPortal[i]){
            for(int j=0;j<i;j++)
                Result.push_back(NonPortal[j]);
            for(int p : Portal)
                Result.push_back(p);
            for(int j=i;j<NonPortal.size();j++)
                Result.push_back(NonPortal[j]);
            break;
        }
    }
    if(Result.size() == 0){
        Result.insert(Result.end(),NonPortal.begin(),NonPortal.end());
        Result.insert(Result.end(),Portal.begin(),Portal.end());
    }
    PRINT(Result)
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}
