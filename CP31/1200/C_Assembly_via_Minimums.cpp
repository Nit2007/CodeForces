#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//1857C
        ll n;cin>>n;
        ll m = (n * (n-1))/2 ;
        vector<ll>nums = readVector<ll>(m);

        sort(nums.begin(),nums.end());
        for(int i=0;i<m;i+= (--n)){
            cout<<nums[i]<<" ";
        }
        cout<<INF;N();
        //Always the smallest number is going to repeat n-1 times
        //Always 2nd smallest number is going to repeat n-2 times ....
        //Always the largest  number is going to repeat  0 times ....
        //Putting the smallest(or any) number anywhere is not going to change this property, hence
        // for conveinance ,lets consider the ans is sorted 
    }
    // map<ll,ll>freq;
    // for(auto i:nums){
    //     freq[i]++;
    // }
    // vector<ll>ans(n,INF);
    // int i = 0;
    // for(auto x:freq){
    //     ans[i++] = x.first;
    // }
    // for(int i=0;i<n;i++){
    //     if(ans[i] == INF && i > 0){
    //         ans[i] = ans[i-1];
    //     }
    // }
    // PRINT(ans);





    int run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z;cin>>z;
        while(z--){ solve();}
        return 0;
    }
    


    template<typename T>
    void PRINT(const vector<T>& v){
        for(int i1=0;i1<(int)v.size();i1++) cout<<v[i1]<<" ";
        cout<<endl;
    }

    template<typename T>
    void PRINTS(const string& s,const vector<T>& v){
        cout<<s<<" : ";
        for(int i1=0;i1<(int)v.size();i1++) cout<<v[i1]<<" ";
        cout<<endl;
    }
    void N(){cout<<"\n";}
    void ND(){cout<<"---DEBUG___";cout<<"\n";}

    template<typename T>
    vector<T> readVector(int n){
        vector<T> v((unsigned int)n);
        for(auto &x : v) cin >> x;
        return v;
    }
    template<typename T>
    vector<T> makeUnique(vector<T>& v){
        unordered_set<T>seen;
        vector<T>unique;
        for(auto &x:v){
            if(seen.insert(x).second)unique.push_back(x);
        }return unique;
    }
};

int main(){
    Main OBJ;
    return OBJ.run();
}
