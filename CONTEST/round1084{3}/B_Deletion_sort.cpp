#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int;
#define PRINT(v) for(int i1=0;i1<(int)v.size();i1++)cout<<v[i1]<<" ";cout<<endl;
#define N cout<<endl; 

void solve(){//2200B
    int n;cin>>n;
    vector<int>nums(n);
    for(int j=0;j<n;j++){
        cin>>nums[j];
    }
    for(int i=1;i<n;i++){
        if(nums[i-1] > nums[i]){//Greedily delete the back elements to minmize the value
            cout<<1;N
            return ;
        }
    }
    cout<<n;N
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}
