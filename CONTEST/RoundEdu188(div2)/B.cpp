#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  
    static void solve(){//2204B
        int n;cin>>n;
        vector<int>nums(n);
        for(int j=0;j<n;j++){
            cin>>nums[j];
        }
        vector<int>leftMax(n+1,0);
        for(int i=1;i<=n;i++){
            leftMax[i] = max(leftMax[i-1],nums[i-1]);
        }
        // PRINT(leftMax);
        int count = 0;
        for(int i=0;i<n;i++){
            if(leftMax[i+1] == nums[i]){
                count++;
            }
        }
        cout<<count;N();
    }

    static int run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z;cin>>z;
        while(z--){ solve();}
        return 0;
    }
    


    template<typename T>
    static void PRINT(const vector<T>& v){
        for(int i1=0;i1<(int)v.size();i1++) cout<<v[i1]<<" ";
        cout<<endl;
    }

    template<typename T>
    static void PRINTS(const string& s,const vector<T>& v){
        cout<<s<<" : ";
        for(int i1=0;i1<(int)v.size();i1++) cout<<v[i1]<<" ";
        cout<<endl;
    }
    static void N(){cout<<endl;}
};

int main(){
    return Main::run();
}