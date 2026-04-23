#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  
    void solve(){//1828B
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);
        ll k = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == i+1)continue;//Correct
            int misplaced = nums[i]-1 - i;
            k = gcd(k, misplaced);//we want a K which is divisible by all displacements
        }
        if(k == 0)k=1;
        cout<<k<<endl;
    }
    // void solve(){//1828B
    //     int n;cin>>n;
    //     vector<int>nums = readVector<int>(n);
    //     ll k = LONG_MAX;
    //     for(int i=0;i<n;i++){
    //         if(nums[i] == i+1)continue;//Correct
    //         k = min(k,(ll)abs(nums[i] - nums[nums[i]-1]));//we want to move current_(nums[i]) to its correct position_(nums[nums[i]-1])
    //     }
    //     cout<<k<<endl;
    // }


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
        vector<T> v(n);
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